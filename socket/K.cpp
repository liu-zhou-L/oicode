#include "winsock2.h"  
#include <string>
#include<conio.h>
#include "cgame.h"
#pragma comment(lib, "ws2_32.lib")
#include<iostream>
//172.16.14.50
using namespace std;
#define CreateServer 0
#define ConnectServer 1
int main() {
	WSADATA wsd;
	SOCKADDR_IN Server_IP;
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
		while(1)
			if (_kbhit() flag=getch();
		system("color 0a");
		system("cls");
		//if(flag==CreateServer)
		if(flag==ConnectServer) {
			printf("Enter connection IP:");
			Server_IP.sin_family = AF_INET;
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
