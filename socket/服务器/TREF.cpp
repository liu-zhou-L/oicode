//-static-libgcc-lwsock32
#include <stdio.h>

#include <windows.h>//包含window封装的通信相关的结构及接口

#include<string>
//加载静态库，该库包含WSAStartup，WSAClean,socket等接口
#pragma comment(lib, "ws2_32.lib")
//1. 将收到的客户端请求的socket存在数组里面，用于保存多个客户端的连接
struct IP{
	SOCKET clientSocket;
	char huaji[1024];
	bool flag=1;
}name[1024];
#include "server.h"

char g_szNewFileName[MAXFILEDIRLENGTH];
char g_szBuff[MAX_PACKET_SIZE + 1];
long g_lLength;
char* g_pBuff = NULL;

// 初始化socket库
bool InitSocket();
// 关闭socket库
bool CloseSocket();
// 解析消息进行相应的处理
bool ProcessMsg(SOCKET sClient);
// 监听Client的消息
void ListenToClient();
// 打开文件
bool OpenFile(CCSDef::TMSG_HEADER* pMsgHeader, SOCKET sClient);
// 传送文件
bool SendFile(SOCKET sClient);
// 读取文件进入缓冲区
bool ReadFile(SOCKET sClient);

int ID_xp()
{
InitSocket();
ListenToClient();
CloseSocket();

return 0;
}

void ListenToClient()
{
// 创建socket套接字
SOCKET sListen = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (SOCKET_ERROR == sListen)
{
   printf("Init Socket Error!\n");
   return;
}

// 绑定socket到一个本地地址
sockaddr_in sin;
sin.sin_family = AF_INET;
sin.sin_port = htons(PORT);
sin.sin_addr.S_un.S_addr = INADDR_ANY;
if (::bind(sListen, (LPSOCKADDR)&sin, sizeof(sockaddr_in)) == SOCKET_ERROR)
{
   printf("Bind Error!\n");
   return;
}

// 设置socket进入监听状态
if (::listen(sListen, 10) == SOCKET_ERROR)
{
   printf("Listen Error!\n");
   return;
}

printf("Listening To Client...\n");

// 循环接收client端的连接请求
sockaddr_in ClientAddr;
int nAddrLen = sizeof(sockaddr_in);
SOCKET sClient;

while (INVALID_SOCKET == (sClient = ::accept(sListen, (sockaddr*)&ClientAddr, &nAddrLen)))
{
}

while (true == ProcessMsg(sClient))
{
}

// 关闭同客户端的连接
::closesocket(sClient);

::closesocket(sListen);
}

bool InitSocket()
{
// 初始化socket dll
WSADATA wsaData;
WORD socketVersion = MAKEWORD(2, 2);
if (::WSAStartup(socketVersion, &wsaData) != 0)
{
   printf("Init socket dll error\n");
   return false;
}

return true;
}

bool CloseSocket()
{
// 释放winsock库
::WSACleanup();

if (NULL != g_pBuff)
{
   delete [] g_pBuff;
   g_pBuff = NULL;
}

return true;
}

bool ProcessMsg(SOCKET sClient)
{
int nRecv = ::recv(sClient, g_szBuff, MAX_PACKET_SIZE + 1, 0);
if (nRecv > 0)
{
   g_szBuff[nRecv] = '\0';
}

// 解析命令
CCSDef::TMSG_HEADER* pMsgHeader = (CCSDef::TMSG_HEADER*)g_szBuff;
switch (pMsgHeader->cMsgID)
{
case MSG_FILENAME:    // 文件名
   {
    OpenFile(pMsgHeader, sClient);
   }
   break;
case MSG_CLIENT_READY:   // 客户端准备好了,开始传送文件
   {
    SendFile(sClient);
   }
   break;
case MSG_SENDFILESUCCESS: // 传送文件成功
   {
    printf("Send File Success!\n");
    return false;
   }
   break;
case MSG_FILEALREADYEXIT_ERROR: // 要保存的文件已经存在了
   {
    printf("The file reay to send already exit!\n");
    return false;
   }
   break;
}

return true;
}

bool ReadFile(SOCKET sClient)
{
if (NULL != g_pBuff)
{
   return true;
}

// 打开文件
FILE *pFile;
if (NULL == (pFile = fopen(g_szNewFileName, "rb")))   // 打开文件失败
{
   printf("Cannot find the file, request the client input file name again\n");
   CCSDef::TMSG_ERROR_MSG tMsgErrorMsg(MSG_OPENFILE_ERROR);
   ::send(sClient, (char*)(&tMsgErrorMsg), sizeof(CCSDef::TMSG_ERROR_MSG), 0);
   return false;
}

// 把文件的长度传回到client去
fseek(pFile, 0, SEEK_END);
g_lLength = ftell(pFile);
printf("File Length = %d\n", g_lLength);
CCSDef::TMSG_FILELENGTH tMsgFileLength(g_lLength);
::send(sClient, (char*)(&tMsgFileLength), sizeof(CCSDef::TMSG_FILELENGTH), 0);

// 处理文件全路径名,把文件名分解出来
char szDrive[_MAX_DRIVE], szDir[_MAX_DIR], szFname[_MAX_FNAME], szExt[_MAX_EXT];
_splitpath(g_szNewFileName, szDrive, szDir, szFname, szExt);
strcat(szFname,szExt);
CCSDef::TMSG_FILENAME tMsgFileName;
strcpy(tMsgFileName.szFileName, szFname);
printf("Send File Name: %s\n", tMsgFileName.szFileName);
::send(sClient, (char*)(&tMsgFileName), sizeof(CCSDef::TMSG_FILENAME), 0);

// 分配缓冲区读取文件内容
g_pBuff = new char[g_lLength + 1];
if (NULL == g_pBuff)
{
   return false;
}

fseek(pFile, 0, SEEK_SET);
fread(g_pBuff, sizeof(char), g_lLength, pFile);
g_pBuff[g_lLength] = '\0';
fclose(pFile);

return true;
}

// 打开文件
bool OpenFile(CCSDef::TMSG_HEADER* pMsgHeader, SOCKET sClient)
{
CCSDef::TMSG_FILENAME* pRequestFilenameMsg = (CCSDef::TMSG_FILENAME*)pMsgHeader;

// 对文件路径名进行一些处理
char *p1, *p2;
for (p1 = pRequestFilenameMsg->szFileName, p2 = g_szNewFileName;
   '\0' != *p1;
   ++p1, ++p2)
{
   if ('\n' != *p1)
   {
    *p2 = *p1;
   }
   if ('\\' == *p2)
   {
    *(++p2) = '\\';
   }
}
*p2 = '\0';

ReadFile(sClient);

return true;
}

// 传送文件
bool SendFile(SOCKET sClient)
{
if (NULL == g_pBuff)
{
   ReadFile(sClient);
}

int nPacketBufferSize = MAX_PACKET_SIZE - 2 * sizeof(int); // 每个数据包存放文件的buffer大小
// 如果文件的长度大于每个数据包所能传送的buffer长度那么就分块传送
for (int i = 0; i < g_lLength; i += nPacketBufferSize)
{  
   CCSDef::TMSG_FILE tMsgFile;
   tMsgFile.tFile.nStart = i;
   if (i + nPacketBufferSize + 1> g_lLength)
   {
    tMsgFile.tFile.nSize = g_lLength - i;
   }
   else
   {
    tMsgFile.tFile.nSize = nPacketBufferSize;
   }
   //printf("start = %d, size = %d\n", tMsgFile.tFile.nStart, tMsgFile.tFile.nSize);
   memcpy(tMsgFile.tFile.szBuff, g_pBuff + tMsgFile.tFile.nStart, tMsgFile.tFile.nSize);
   ::send(sClient, (char*)(&tMsgFile), sizeof(CCSDef::TMSG_FILE), 0);
   Sleep(0.5);
}

delete [] g_pBuff;
g_pBuff = NULL;

return true;
}
void Zhuan_huan(char a[])
{
	for(int i=strlen(a)-1;i>=0;i--)
	{
		a[i+1]=a[i]; 
	}
}

//2. 构建变量实时记录连接进来的客户端的编号及总数，记录连接客户端的个数
int count = 0;

//3. 将通信逻辑封装成函数，负责接收指定客户端的消息，并分发给所有客户端
//idx用于标识哪个客户端
void Communication(int idx)
{
	//7. 通信
	char buff[9999+2];
	int r = 0;
	while(1)
	{
		memset(buff, 0, 9999+2);
		//接收客户端发过来的消息
		r = recv(name[idx].clientSocket/*[idx]*/, buff, 9999+2, NULL);
		if(r > 0)
		{
			buff[r+1]='\n';
			buff[r+2] = 0;
			Zhuan_huan(buff);
			buff[0]=':';
			Zhuan_huan(buff);
			buff[0]=idx+48;
			//字符串的结束符 
//			buff[r+2] = 'P'; //please enter
//			buff[r+3] = 'l'; 
//			buff[r+4] = 'e'; 
//			buff[r+5] = 'a'; 
//			buff[r+6] = 's'; 
//			buff[r+7] = 'e'; 
//			buff[r+8] = ' ';
//			buff[r+9] = 'e';
//			buff[r+10] = 'n';
//			buff[r+11] = 't';
//			buff[r+12] = 'e';
//			buff[r+13] = 'r';
//			buff[r+14] = '\0'; 
			//打印接收到的消息
			printf("%s\n", buff);
			//将收到的消息分发给所有的客户端
			for(int i = 0; i < count; i++)
			{
				//send(name[i].clientSocket/*[i]*/, ppx[0], strlen(ppx), NULL);
				send(name[i].clientSocket/*[i]*/, buff, strlen(buff), NULL);
			}

		}

	}

}
void IP666()
{
	system("ipconfig");
	system("PAUSE");
	system("cls");
}
int main()
{
	//1. 请求协议版本2.2
	SetConsoleTitle("服务器");
	printf("请查看IP地址(IPv4):\n");
	IP666();
	printf("1.文件服务器\n2.聊天服务器\n请输入：");
	int S;
	scanf("%d",&S);
	if(S==1)
	{
		ID_xp();
	 } 
	 else
	 {
	 		WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);//wsaData存储返回的协议版本
	if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		printf("请求协议版本失败!\n");
		return -1;
	}
	printf("请求协议版本成功!\n");

	//2. 创建socket
	//para1 —— 通信协议类型
	//para2 —— 通信所用的数据类型，TCP使用的是数据流
	//para3 —— 保护方式
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(SOCKET_ERROR == serverSocket)//-1
	{
		printf("创建socket失败\n!");
		//清理协议
		WSACleanup();
		return -2;
	}
	printf("创建socket成功!\n");

	//3. 创建协议地址族
	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;//协议版本
//	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//IP地址，inet_addr将字符串转成整数存储
	addr.sin_port = htons(10086);//端口号，0~65535，一般用10000左右的端口

	//4. 将socket和协议地址族绑定在一起
	int r = bind(serverSocket, (sockaddr*)&addr, sizeof(addr));
	if(-1 == r)
	{
		printf("绑定失败!\n");
		//关闭socket
		closesocket(serverSocket);
		//清理协议
		WSACleanup();
		return -3;
	
	}

	//5. 监听socket(防止有多个客户端同时连接服务器，则创建队列进行排队，10表示队列长度)
	r = listen(serverSocket, 10);
	if(-1 == r)
	{
		printf("监听失败!\n");
		//关闭socket
		closesocket(serverSocket);
		//清理协议
		WSACleanup();
		return -4;
	}
	printf("监听成功!\n");

	//4. 循环接收客户端请求，并保存起来
//每接收一个客户端请求，则单独创建一个线程用于通信
	//6. 等待客户连接（阻塞函数，尾生抱柱）
	//循环接收客户端连接请求
	SOCKADDR_IN clientAddr = { 0 };//存储客户端的地址族
	int len = sizeof(clientAddr);
	while(1)
	{

		name[count].clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &len);
		if(SOCKET_ERROR == name[count].clientSocket)//若有客户请求，但请求失败
		{
			printf("服务器宕机!\n");
			//关闭socket
			closesocket(serverSocket);
			//清理协议
			WSACleanup();
			return -5;
		}
		int fllag=0;
		count++;
//		while(fllag>0)
//		{
//			fllag=recv(serverSocket, name[count-1].huaji, sizeof(name[count-1].huaji), 0);
//		}
		char ppx[100]={count+47};
		printf("用户%d连接了\n",count-1);
		send(name[count-1].clientSocket/*[i]*/, ppx, strlen(ppx), NULL);
		printf("其IP为: %s\n", inet_ntoa(clientAddr.sin_addr));//inet_ntoa将整形IP转成字符串
		//一旦有客户端连接，则专门创建一个线程，用于服务器与该客户端的通信
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Communication,(LPVOID)(count-1), NULL,NULL);
	}
	//7. 通信
	char buff[1024];
	while(1)
	{
		//接收客户端发过来的消息
		recv(serverSocket, buff, sizeof(buff), 0); 
			//打印接收到的消息
			printf(">>%s\n", buff);
	}
	getchar();
	return 0;
	 }

}
