//172.16.12.26
#include "winsock2.h"  
#include <string>
#pragma comment(lib, "ws2_32.lib")  //附加依赖lib库 也可以在属性中设置
#include<iostream>
using namespace std;
 
//数据库相关
 
int main()
{
	
	WSADATA         wsd;            //WSADATA变量  
	SOCKET          sServer;        //服务器套接字  用来监听
	SOCKET          sClient;        //客户端套接字  连接
	SOCKADDR_IN     addrServ;;      //服务器地址  
	const int BUF_SIZE = 500;
	char            buf[BUF_SIZE];  //接收数据缓冲区  
	char            sendBuf[BUF_SIZE];//返回给客户端得数据  
	int             retVal;         //返回值  
	//初始化套结字动态库  代码健壮
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return 1;
	}
 
	//开始创建服务端socket
	//创建套接字  AF_INET：ipv4   SOCK_STREAM：使用tcp
	sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sServer)
	{
		cout << "socket failed!" << endl;
		WSACleanup();//释放套接字资源;  
		return  -1;
	}
 
	//服务器套接字地址   
	addrServ.sin_family = AF_INET;//IPv4 
	addrServ.sin_port = htons(4999);//设置端口 建议大于1024
	addrServ.sin_addr.s_addr = INADDR_ANY; //表示接受任何客户端的请求
 
	//绑定套接字  绑定服务端socket 和 端口
	retVal = bind(sServer, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if (SOCKET_ERROR == retVal)
	{
		cout << "bind failed!" << endl;
		closesocket(sServer);   //关闭套接字  
		WSACleanup();           //释放套接字资源;  
		return -1;
	}
 
	//开始监听   
	retVal = listen(sServer, 10);
	if (SOCKET_ERROR == retVal)
	{
		cout << "listen failed!" << endl;
		closesocket(sServer);   //关闭套接字  
		WSACleanup();           //释放套接字资源;  
		return -1;
	}
 
	//接受客户端请求  
	sockaddr_in addrClient;
	int addrClientlen = sizeof(addrClient);
	sClient = accept(sServer, (sockaddr FAR*)&addrClient, &addrClientlen);//使用sClient进行数据收发
	if (INVALID_SOCKET == sClient)
	{
		cout << "accept failed!" << endl;
		closesocket(sServer);   //关闭套接字  
		WSACleanup();           //释放套接字资源;  
		return -1;
	}
 
	while (1)
	{
		//接收客户端数据  
		ZeroMemory(buf, BUF_SIZE);//初始化 buf  用 0填充
		ZeroMemory(sendBuf, BUF_SIZE);
		retVal = recv(sClient, buf, BUF_SIZE, 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "recv failed!" << endl;
			closesocket(sServer);   //关闭套接字  
			closesocket(sClient);   //关闭套接字       
			WSACleanup();           //释放套接字资源;  
			return -1;
		}
 
		cout << "set:" << buf << endl;
		//对客户端的数据进行解析
		if (buf[0] == '1')
		{
			cout << "dl" ;
			//解析内容
			/*
			struct info
			{
			int		flag; 指令
			char*  username;
			char* password;
			其他结构体
				int		flag; 指令
			}
			*/
		}
		if (buf[0] == '2')
		{
			cout << "zc";
		}
		//向客户端发送数据
		cout << "go:";
		cin >> sendBuf;
		send(sClient, sendBuf, strlen(sendBuf), 0);
	}
	
 
	//关闭连接 释放资源
	closesocket(sServer);   //关闭套接字  
	closesocket(sClient);   //关闭套接字  
	WSACleanup();           //释放套接字资源;  
 
	system("pause");
	return 0;
}
 //-static-libgcc
