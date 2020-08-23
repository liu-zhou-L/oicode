//-static-libgcc-lwsock32
#include <stdio.h>

#include <windows.h>//����window��װ��ͨ����صĽṹ���ӿ�

#include<string>
//���ؾ�̬�⣬�ÿ����WSAStartup��WSAClean,socket�Ƚӿ�
#pragma comment(lib, "ws2_32.lib")
//1. ���յ��Ŀͻ��������socket�����������棬���ڱ������ͻ��˵�����
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

// ��ʼ��socket��
bool InitSocket();
// �ر�socket��
bool CloseSocket();
// ������Ϣ������Ӧ�Ĵ���
bool ProcessMsg(SOCKET sClient);
// ����Client����Ϣ
void ListenToClient();
// ���ļ�
bool OpenFile(CCSDef::TMSG_HEADER* pMsgHeader, SOCKET sClient);
// �����ļ�
bool SendFile(SOCKET sClient);
// ��ȡ�ļ����뻺����
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
// ����socket�׽���
SOCKET sListen = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (SOCKET_ERROR == sListen)
{
   printf("Init Socket Error!\n");
   return;
}

// ��socket��һ�����ص�ַ
sockaddr_in sin;
sin.sin_family = AF_INET;
sin.sin_port = htons(PORT);
sin.sin_addr.S_un.S_addr = INADDR_ANY;
if (::bind(sListen, (LPSOCKADDR)&sin, sizeof(sockaddr_in)) == SOCKET_ERROR)
{
   printf("Bind Error!\n");
   return;
}

// ����socket�������״̬
if (::listen(sListen, 10) == SOCKET_ERROR)
{
   printf("Listen Error!\n");
   return;
}

printf("Listening To Client...\n");

// ѭ������client�˵���������
sockaddr_in ClientAddr;
int nAddrLen = sizeof(sockaddr_in);
SOCKET sClient;

while (INVALID_SOCKET == (sClient = ::accept(sListen, (sockaddr*)&ClientAddr, &nAddrLen)))
{
}

while (true == ProcessMsg(sClient))
{
}

// �ر�ͬ�ͻ��˵�����
::closesocket(sClient);

::closesocket(sListen);
}

bool InitSocket()
{
// ��ʼ��socket dll
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
// �ͷ�winsock��
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

// ��������
CCSDef::TMSG_HEADER* pMsgHeader = (CCSDef::TMSG_HEADER*)g_szBuff;
switch (pMsgHeader->cMsgID)
{
case MSG_FILENAME:    // �ļ���
   {
    OpenFile(pMsgHeader, sClient);
   }
   break;
case MSG_CLIENT_READY:   // �ͻ���׼������,��ʼ�����ļ�
   {
    SendFile(sClient);
   }
   break;
case MSG_SENDFILESUCCESS: // �����ļ��ɹ�
   {
    printf("Send File Success!\n");
    return false;
   }
   break;
case MSG_FILEALREADYEXIT_ERROR: // Ҫ������ļ��Ѿ�������
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

// ���ļ�
FILE *pFile;
if (NULL == (pFile = fopen(g_szNewFileName, "rb")))   // ���ļ�ʧ��
{
   printf("Cannot find the file, request the client input file name again\n");
   CCSDef::TMSG_ERROR_MSG tMsgErrorMsg(MSG_OPENFILE_ERROR);
   ::send(sClient, (char*)(&tMsgErrorMsg), sizeof(CCSDef::TMSG_ERROR_MSG), 0);
   return false;
}

// ���ļ��ĳ��ȴ��ص�clientȥ
fseek(pFile, 0, SEEK_END);
g_lLength = ftell(pFile);
printf("File Length = %d\n", g_lLength);
CCSDef::TMSG_FILELENGTH tMsgFileLength(g_lLength);
::send(sClient, (char*)(&tMsgFileLength), sizeof(CCSDef::TMSG_FILELENGTH), 0);

// �����ļ�ȫ·����,���ļ����ֽ����
char szDrive[_MAX_DRIVE], szDir[_MAX_DIR], szFname[_MAX_FNAME], szExt[_MAX_EXT];
_splitpath(g_szNewFileName, szDrive, szDir, szFname, szExt);
strcat(szFname,szExt);
CCSDef::TMSG_FILENAME tMsgFileName;
strcpy(tMsgFileName.szFileName, szFname);
printf("Send File Name: %s\n", tMsgFileName.szFileName);
::send(sClient, (char*)(&tMsgFileName), sizeof(CCSDef::TMSG_FILENAME), 0);

// ���仺������ȡ�ļ�����
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

// ���ļ�
bool OpenFile(CCSDef::TMSG_HEADER* pMsgHeader, SOCKET sClient)
{
CCSDef::TMSG_FILENAME* pRequestFilenameMsg = (CCSDef::TMSG_FILENAME*)pMsgHeader;

// ���ļ�·��������һЩ����
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

// �����ļ�
bool SendFile(SOCKET sClient)
{
if (NULL == g_pBuff)
{
   ReadFile(sClient);
}

int nPacketBufferSize = MAX_PACKET_SIZE - 2 * sizeof(int); // ÿ�����ݰ�����ļ���buffer��С
// ����ļ��ĳ��ȴ���ÿ�����ݰ����ܴ��͵�buffer������ô�ͷֿ鴫��
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

//2. ��������ʵʱ��¼���ӽ����Ŀͻ��˵ı�ż���������¼���ӿͻ��˵ĸ���
int count = 0;

//3. ��ͨ���߼���װ�ɺ������������ָ���ͻ��˵���Ϣ�����ַ������пͻ���
//idx���ڱ�ʶ�ĸ��ͻ���
void Communication(int idx)
{
	//7. ͨ��
	char buff[9999+2];
	int r = 0;
	while(1)
	{
		memset(buff, 0, 9999+2);
		//���տͻ��˷���������Ϣ
		r = recv(name[idx].clientSocket/*[idx]*/, buff, 9999+2, NULL);
		if(r > 0)
		{
			buff[r+1]='\n';
			buff[r+2] = 0;
			Zhuan_huan(buff);
			buff[0]=':';
			Zhuan_huan(buff);
			buff[0]=idx+48;
			//�ַ����Ľ����� 
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
			//��ӡ���յ�����Ϣ
			printf("%s\n", buff);
			//���յ�����Ϣ�ַ������еĿͻ���
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
	//1. ����Э��汾2.2
	SetConsoleTitle("������");
	printf("��鿴IP��ַ(IPv4):\n");
	IP666();
	printf("1.�ļ�������\n2.���������\n�����룺");
	int S;
	scanf("%d",&S);
	if(S==1)
	{
		ID_xp();
	 } 
	 else
	 {
	 		WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);//wsaData�洢���ص�Э��汾
	if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		printf("����Э��汾ʧ��!\n");
		return -1;
	}
	printf("����Э��汾�ɹ�!\n");

	//2. ����socket
	//para1 ���� ͨ��Э������
	//para2 ���� ͨ�����õ��������ͣ�TCPʹ�õ���������
	//para3 ���� ������ʽ
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(SOCKET_ERROR == serverSocket)//-1
	{
		printf("����socketʧ��\n!");
		//����Э��
		WSACleanup();
		return -2;
	}
	printf("����socket�ɹ�!\n");

	//3. ����Э���ַ��
	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;//Э��汾
//	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//IP��ַ��inet_addr���ַ���ת�������洢
	addr.sin_port = htons(10086);//�˿ںţ�0~65535��һ����10000���ҵĶ˿�

	//4. ��socket��Э���ַ�����һ��
	int r = bind(serverSocket, (sockaddr*)&addr, sizeof(addr));
	if(-1 == r)
	{
		printf("��ʧ��!\n");
		//�ر�socket
		closesocket(serverSocket);
		//����Э��
		WSACleanup();
		return -3;
	
	}

	//5. ����socket(��ֹ�ж���ͻ���ͬʱ���ӷ��������򴴽����н����Ŷӣ�10��ʾ���г���)
	r = listen(serverSocket, 10);
	if(-1 == r)
	{
		printf("����ʧ��!\n");
		//�ر�socket
		closesocket(serverSocket);
		//����Э��
		WSACleanup();
		return -4;
	}
	printf("�����ɹ�!\n");

	//4. ѭ�����տͻ������󣬲���������
//ÿ����һ���ͻ��������򵥶�����һ���߳�����ͨ��
	//6. �ȴ��ͻ����ӣ�����������β��������
	//ѭ�����տͻ�����������
	SOCKADDR_IN clientAddr = { 0 };//�洢�ͻ��˵ĵ�ַ��
	int len = sizeof(clientAddr);
	while(1)
	{

		name[count].clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &len);
		if(SOCKET_ERROR == name[count].clientSocket)//���пͻ����󣬵�����ʧ��
		{
			printf("������崻�!\n");
			//�ر�socket
			closesocket(serverSocket);
			//����Э��
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
		printf("�û�%d������\n",count-1);
		send(name[count-1].clientSocket/*[i]*/, ppx, strlen(ppx), NULL);
		printf("��IPΪ: %s\n", inet_ntoa(clientAddr.sin_addr));//inet_ntoa������IPת���ַ���
		//һ���пͻ������ӣ���ר�Ŵ���һ���̣߳����ڷ�������ÿͻ��˵�ͨ��
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Communication,(LPVOID)(count-1), NULL,NULL);
	}
	//7. ͨ��
	char buff[1024];
	while(1)
	{
		//���տͻ��˷���������Ϣ
		recv(serverSocket, buff, sizeof(buff), 0); 
			//��ӡ���յ�����Ϣ
			printf(">>%s\n", buff);
	}
	getchar();
	return 0;
	 }

}
