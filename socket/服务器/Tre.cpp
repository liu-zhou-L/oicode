#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <cstdio>
#include <cstring>
#pragma comment(lib, "ws2_32.lib")
int main()
{    //�����׽���    
	   //�����׽���
	char a[1000000];
	scanf("%s",a);
	//a[strlen(a)]='0';
	//CmdExc cmd("ipconfig");
	//cout<<cmd.getOutput().c_str()<<endl;
    while(1)
    {WSADATA wsaData;    char buff[1024];
    memset(buff, 0, sizeof(buff));    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Failed to load Winsock");        return 0;
    }

    SOCKADDR_IN addrSrv;
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(5099);
    addrSrv.sin_addr.S_un.S_addr = inet_addr(a); 
    	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);    if (SOCKET_ERROR == sockClient){
        printf("Socket() error:%d", WSAGetLastError());        return 0;
    }    //�������������������
    if (connect(sockClient, (struct  sockaddr*)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET){
        printf("Connect failed:%d", WSAGetLastError());        return 0;
    }    else
    {   
	     //��������
	     printf("���ӳɹ���\nConnection succeeded!");
        recv(sockClient, buff, sizeof(buff), 0); 
        printf("%s\n", buff);
    }    //��������
    char qaq[1024];
    gets(qaq);
    char *buffSend = qaq;
    send(sockClient, buffSend, strlen(buffSend) + 1, 0);
    //printf("%d", strlen(buffSend) + 1);    //�ر��׽���    closesocket(sockClient);
    WSACleanup();
    //system("PAUSE");
	}
}
