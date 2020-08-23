#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<windows.h>
#include<iostream>
#include<string>
#include<conio.h>
#include "winsock2.h"
#include "cgame.h"
#pragma comment(lib, "ws2_32.lib")
//172.16.14.50
using namespace std;
#define CreateServer 0
#define ConnectServer 1
/*
int get_keyboard() {
	int a
	if(_kbhit()) a=getch();
	else return -1;
	return a;
}
*/
int main() {
	WSADATA wsd;
	SOCKADDR_IN Server_IP;
	SOCKET sClient[20],sSever;
	SOCKET sHost;
	char Server_IPs[20]={},prints[5000],scans[5000];
	int ret,flag;
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0) {
		MessageBox(NULL,"Socket version error!","Tips",MB_OK);
		return -1;
	}
	sHost=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sHost) {
		MessageBox(NULL,"socket failed!","Tips",MB_OK);
		WSACleanup(); 
		return  -1;
	}
	Button Create_server=NewButton(0,0,1,"[Create server]"),Connect_server=NewButton(1,0,1,"[Connect to server]");
	while(1) {
		system("color 0a");
		HideCursor();
		while(1) {
			if(Preserve(Create_server)) {
				flag=0;	
				break;
			}
			else if(Preserve(Connect_server)) {
				flag=1;
				break;
			}
			Sleep(20);
		}
		system("color 0a");
		system("cls");
		if(flag==CreateServer) {
			printf("Monitoring...");
			Server_IP.sin_family = AF_INET;//IPv4 
			Server_IP.sin_port = htons(4999);//设置端口 建议大于1024
			Server_IP.sin_addr.s_addr = INADDR_ANY; //表示接受任何客户端的请求
			ret = bind(sServer, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));//绑定套接字  绑定服务端socket 和 端口
			while()
		}
		if(flag==ConnectServer) {
			Server_IP.sin_family = AF_INET;
			printf("Enter connection IP:");
			/*
			AF_INET	IPv4网络协议中采用的地址族
			AF_INET6	IPv6网络协议中采用的地址族
			AF_LOCAL	本地通信中采用的UNIX协议的地址族（用的少）
			*/
			scanf("%s",Server_IPs);
			Server_IP.sin_addr.s_addr = inet_addr(Server_IPs);
			Server_IP.sin_port = htons((short)4999);
			int nServAddlen = sizeof(Server_IP);
			ret=connect(sHost, (LPSOCKADDR)&Server_IP, sizeof(Server_IP));
			if (SOCKET_ERROR == ret) {
				MessageBox(NULL,"connect failed!","Tips",MB_OK);
				system("cls");
				continue;
			}
		}
		system("cls");
		while(1) {
			printf("out:");
			scanf("%s",&prints);
			ret=send(sHost,prints, strlen(prints), 0);
			recv(sHost, scans, 500, 0);
			printf("in:%s\n",scans);
		}
	}
	printf("Withdraw from...");
	closesocket(sHost);
	WSACleanup(); 
	return 0;
}
