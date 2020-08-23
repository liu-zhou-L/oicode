#include "winsock2.h"  
#include <string>
#include <iostream>  
#pragma comment(lib, "ws2_32.lib")
 
using namespace std;
 
int main()
{
	WSADATA wsd; //WSADATA变量  
	SOCKET sHost; //客户端套接字  
	SOCKADDR_IN servAddr; //服务器地址  
 
	const int BUF_SIZE = 500;
	char buf[BUF_SIZE]; //接收数据缓冲区  
	char bufRecv[BUF_SIZE];
	int retVal; //返回值  
	//初始化套结字动态库 
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return -1;
	}
	//创建套接字  
	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sHost)
	{
		cout << "socket failed!" << endl;
		WSACleanup();//释放套接字资源  
		return  -1;
	}
	servAddr.sin_family = AF_INET;
	//如果编译通不过 属性 c++ 常规  sdl 改成否
	char inte[20];
	scanf("%s",inte);
	servAddr.sin_addr.s_addr = inet_addr(inte);//设置服务端地址  这里表示本机
	servAddr.sin_port = htons((short)4999);
	int nServAddlen = sizeof(servAddr);
 
	//连接服务器  
	retVal = connect(sHost, (LPSOCKADDR)&servAddr, sizeof(servAddr));
	if (SOCKET_ERROR == retVal)
	{
		cout << "connect failed!" << endl;
		closesocket(sHost); //关闭套接字  
		WSACleanup(); //释放套接字资源  
		return -1;
	}
	//成功建立连接  可以开始通信了
	while (1)
	{
		//向服务器发送数据  
		ZeroMemory(buf, BUF_SIZE);
		cout << "go:";
		cin >> buf;
		// 包装数据：   指令标记 ：  内容
		//						1-100 
		//						1:登录  username - passeord 2：注册  3 查询  4 更新数据库 5 .....
		/*
			struct info
			{
				int		flag; 指令
				char*  username;
				char* password;
				其他结构体
			}
			
		*/
		retVal = send(sHost, buf, strlen(buf), 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "send failed!" << endl;
			closesocket(sHost); //关闭套接字  
			WSACleanup(); //释放套接字资源  
			return -1;
		}
		ZeroMemory(bufRecv, BUF_SIZE);
		recv(sHost, bufRecv, BUF_SIZE, 0); // 接收服务器端的数据
		cout << endl << "set:" << bufRecv;
		cout << "\n";
	}
	
 
	closesocket(sHost); //关闭套接字  
	WSACleanup(); //释放套接字资源  
	system("pause");
	return 0;
}
