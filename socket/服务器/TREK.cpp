#include <stdio.h>

#include <windows.h>//����window��װ��ͨ����صĽṹ���ӿ�

//���ؾ�̬�⣬�ÿ����WSAStartup��WSAClean,socket�Ƚӿ�
#pragma comment(lib, "ws2_32.lib")
#include "client.h"
int fuck;
long g_lLength = 0;
char* g_pBuff = NULL;
char g_szFileName[MAXFILEDIRLENGTH];
char g_szBuff[MAX_PACKET_SIZE + 1];
SOCKET g_sClient;

// ��ʼ��socket��
bool InitSocket();
// �ر�socket��
bool CloseSocket();
// ���û�������ļ�·�����͵�server��
bool SendFileNameToServer();
// ��server������
bool ConectToServer();
// ���ļ�ʧ��
bool OpenFileError(CCSDef::TMSG_HEADER *pMsgHeader);
// ����ռ��Ա�д���ļ�
bool AllocateMemoryForFile(CCSDef::TMSG_HEADER *pMsgHeader);
// д���ļ�
bool WriteToFile(CCSDef::TMSG_HEADER *pMsgHeader);
// ����server�˴��͹�������Ϣ
bool ProcessMsg();
char IP[1234];
void ID_xp()
{
	printf("������IP:");
	scanf("%s",IP);
InitSocket();
ConectToServer();
CloseSocket();
return;
}

// ��ʼ��socket��
bool InitSocket()
{
// ��ʼ��socket dll
WSADATA wsaData;
WORD socketVersion = MAKEWORD(2, 2);
if (::WSAStartup(socketVersion, &wsaData) != 0)
{
   printf("Init socket dll error\n");
   exit(-1);
}

return true;
}

// �ر�socket��
bool CloseSocket()
{
// �ر��׽���
::closesocket(g_sClient);
// �ͷ�winsock��
::WSACleanup();

return true;
}

// ��server�����ӽ����ļ��Ĵ���
bool ConectToServer()
{
// ��ʼ��socket�׽���
if (SOCKET_ERROR == (g_sClient = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)))
{
   printf("Init Socket Error!\n");
   exit(-1);
}

sockaddr_in servAddr;
servAddr.sin_family = AF_INET;
servAddr.sin_port = htons(PORT);
servAddr.sin_addr.S_un.S_addr = ::inet_addr(IP);
if (INVALID_SOCKET == (::connect(g_sClient, (sockaddr*)&servAddr, sizeof(sockaddr_in))))
{
   printf("Connect to Server Error!\n");
   exit(-1);
}

// �����ļ�·�����䵽server��
SendFileNameToServer();

// ����server�˴���������Ϣ,ֱ�������ļ��ɹ�Ϊֹ
while (true == ProcessMsg())
{
}

return true;
}

// ���û�������ļ�·�����͵�server��
bool SendFileNameToServer()
{
char szFileName[MAXFILEDIRLENGTH];
printf("Input the File Directory: ");

fgets(szFileName, MAXFILEDIRLENGTH, stdin);

// ���ļ�·������server��
CCSDef::TMSG_FILENAME tMsgRequestFileName;
strcpy(tMsgRequestFileName.szFileName, szFileName);
if (SOCKET_ERROR == ::send(g_sClient, (char*)(&tMsgRequestFileName), sizeof(CCSDef::TMSG_FILENAME), 0))
{
   printf("Send File Name Error!\n");
   exit(-1);
}

return true;
}

// ����server�˴��͹�������Ϣ
bool ProcessMsg()
{
CCSDef::TMSG_HEADER *pMsgHeader;
int nRecv = ::recv(g_sClient, g_szBuff, MAX_PACKET_SIZE + 1, 0);

pMsgHeader = (CCSDef::TMSG_HEADER*)g_szBuff;

switch (pMsgHeader->cMsgID)
{
case MSG_OPENFILE_ERROR:   // ���ļ�����
   {
    OpenFileError(pMsgHeader);
   }
   break;
case MSG_FILELENGTH:    // �ļ��ĳ���
   {
    if (0 == g_lLength)
    {
     g_lLength = ((CCSDef::TMSG_FILELENGTH*)pMsgHeader)->lLength;
     printf("File Length: %d\n", g_lLength);
    }
   }
   break;
case MSG_FILENAME:     // �ļ���
   {
    return AllocateMemoryForFile(pMsgHeader);
   }
   break;
case MSG_FILE:      // �����ļ�,д���ļ��ɹ�֮���˳��������
   {
    if (WriteToFile(pMsgHeader))
    {
     return false;
    }
   }
   break;
}

return true;
}

// ���ļ�ʧ��
bool OpenFileError(CCSDef::TMSG_HEADER *pMsgHeader)
{
if (NULL != g_pBuff)
   return true;
assert(NULL != pMsgHeader);

printf("Cannot find file!Please input again!\n");

// ���������ļ�����
SendFileNameToServer();

return true;
}

// �����Ƿ��Ѿ�������Ҫ������ļ�,ͬʱ���仺���������ļ�
bool AllocateMemoryForFile(CCSDef::TMSG_HEADER *pMsgHeader)
{
assert(NULL != pMsgHeader);

if (NULL != g_pBuff)
{
   return true;
}

CCSDef::TMSG_FILENAME* pRequestFilenameMsg = (CCSDef::TMSG_FILENAME*)pMsgHeader;
printf("File Name: %s\n", pRequestFilenameMsg->szFileName);
system("md ���ܵ��ļ�");
// ���ļ���·������ΪC�̸�Ŀ¼��
strcpy(g_szFileName, "���ܵ��ļ�\\");
strcat(g_szFileName, pRequestFilenameMsg->szFileName);

// ������ͬ�ļ������ļ��Ƿ��Ѿ�����,������ڱ����˳�
FILE* pFile;
if (NULL != (pFile = fopen(g_szFileName, "r")))
{
   // �ļ��Ѿ�����,Ҫ����������һ���ļ�
   printf("The file already exist!\n");
   CCSDef::TMSG_ERROR_MSG tMsgErrorMsg(MSG_FILEALREADYEXIT_ERROR);
   ::send(g_sClient, (char*)(&tMsgErrorMsg), sizeof(CCSDef::TMSG_ERROR_MSG), 0);

   fclose(pFile);
   return false;
}

// ���仺������ʼ�����ļ�,�������ɹ��͸�server�˷��Ϳ�ʼ�����ļ���Ҫ��
g_pBuff = new char[g_lLength + 1];
if (NULL != g_pBuff)
{
   memset(g_pBuff, '\0', g_lLength + 1);
   printf("Now ready to get the file %s!\n", pRequestFilenameMsg->szFileName);
   CCSDef::TMSG_CLIENT_READY tMsgClientReady;

   if (SOCKET_ERROR == ::send(g_sClient, (char*)(&tMsgClientReady), sizeof(CCSDef::TMSG_CLIENT_READY), 0))
   {
    printf("Send Error!\n");
    exit(-1);
   }
}
else
{
   printf("Alloc memory for file error!\n");
   exit(-1);
}

return true;
}

// д���ļ�
bool WriteToFile(CCSDef::TMSG_HEADER *pMsgHeader)
{
assert(NULL != pMsgHeader);

CCSDef::TMSG_FILE* pMsgFile = (CCSDef::TMSG_FILE*)pMsgHeader;

int nStart = pMsgFile->tFile.nStart;
int nSize = pMsgFile->tFile.nSize;
memcpy(g_pBuff + nStart, pMsgFile->tFile.szBuff, nSize);
if (0 == nStart)
{
   printf("Saving file into buffer...\n");
}

memcpy(g_pBuff + nStart, pMsgFile->tFile.szBuff, nSize);
//printf("start = %d, size = %d\n", nStart, nSize);

// ����Ѿ����浽��������Ͼ�д���ļ�
if (nStart + nSize >= g_lLength)
{
   printf("Writing to disk....\n");
   // д���ļ�
   FILE* pFile;
   pFile = fopen(g_szFileName, "w+b");
   fwrite(g_pBuff, sizeof(char), g_lLength, pFile);

   delete [] g_pBuff;
   g_pBuff = NULL;
   fclose(pFile);

   // �����ļ��ɹ�������Ϣ��server�˳�server
   CCSDef::TMSG_SENDFILESUCCESS tMsgSendFileSuccess;
   while (SOCKET_ERROR == ::send(g_sClient, (char*)(&tMsgSendFileSuccess), sizeof(CCSDef::TMSG_SENDFILESUCCESS), 0))
   {
   }

   printf("Save the file %s success!\n", g_szFileName);

   return true;
}
else
{
   return false;
}
}
SOCKET clientSocket;
void ReceiveMsg()
{
	char buff[1024] = { 0 };
	int r = 0;
//	while(1)
//	{
//		r = recv(clientSocket, buff, 1023, NULL);
//		if(r > 0)
//		{
//			Sleep(1000);
//			buff[r] = 0;
//			printf("%s", buff);
//		}
//	}
	while(1)
	{
		//���buff
		memset(buff, 0, 1024);
		Sleep(100);
		int i=0;
		while((buff[i]=getchar())!='\n')
		{
			i++;
		} 
		int IDD=0;
		if(buff[0]=='#')
		{
			
			int len=strlen(buff)-1;
			for(int j=1;j<=len;j++)
			{
				IDD+=buff[j]-48;
				IDD*=10;
			}
			IDD/=10;
			fuck=IDD;
			//ID_xp();
		}
		char MB[8];
		memset(MB, 0, 8);
		MB[0]=IDD+48;
		//����������������
		send(clientSocket, MB, strlen(MB), NULL);
	}
}
int main()
{
	SetConsoleTitle("�ͻ���");
	char a[100];
	printf("1.�����ļ�\n2.Ⱥ��\n�����룺");
	int w;
	scanf("%d",&w);
	if(w==1)
	{
		ID_xp();
	}
	else
	{
		printf("�����������IP��"); 
	scanf("%s",a);
	printf("��ȴ�...");
	Sleep(1000);
	system("cls");
	//1. ����Э��汾2.2
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);//wsaData�洢���ص�Э��汾
	if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		printf("����Э��汾ʧ��!\n");
		system("PAUSE"); 
		return -1;
	}
	printf("����Э��汾�ɹ�!\n");
	Sleep(1000);
	//2. ����socket
	//para1 ���� ͨ��Э������
	//para2 ���� ͨ�����õ��������ͣ�TCPʹ�õ���������
	//para3 ���� ������ʽ
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(SOCKET_ERROR == clientSocket)//-1
	{
		printf("����socketʧ��\n!");
		system("PAUSE"); 
		//����Э��
		WSACleanup();
		return -2;
	}
	printf("����socket�ɹ�!\n");
	//3. ��ȡЭ���ַ��
	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;//Э��汾
	addr.sin_addr.S_un.S_addr = inet_addr(a);//IP��ַ��inet_addr���ַ���ת�������洢
	addr.sin_port = htons(10086);//�˿ںţ�0~65535��һ����10000���ҵĶ˿�
	//4. ���ӷ�����
	int r = connect(clientSocket, (sockaddr*)&addr, sizeof(addr));
	if(-1 == r)
	{
		printf("���ӷ�����ʧ��!\n");
		//�ر�socket
		system("PAUSE"); 
		closesocket(clientSocket);
		//����Э��
		WSACleanup();
		return -2;
	}
	char y[100];
	int xz;
	xz=recv(clientSocket, y, strlen(y), NULL);
	y[xz]=0;
	printf("��ı���:%s",y);
//	char name[1000];
//	memset(name, 0, 1000);
//	system("cls");
//	system("color a");
//	printf("�������û���:");
//	int i=0;
//	while((name[i]=getchar())!='\n')
//	system("PAUSE");
//	send(clientSocket, name, strlen(name), NULL);
	char buff[1024];
//	system("color");
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ReceiveMsg, NULL, NULL, NULL);
//	while(1)
//	{
//		//���buff
//		memset(buff, 0, 1024);
//		printf("\n���������ݣ�");
//		scanf("%s", buff);
//		//����������������
//		send(clientSocket, buff, strlen(buff), NULL);
//	}
	while(1)
	{
		r = recv(clientSocket, buff, 1023, NULL);
		if(r > 0)
		{
			buff[r] = 0;
			//printf("%s:",name);
			printf("%s\n", buff);
		}
	}
	getchar();
	return 0;
}
}	
