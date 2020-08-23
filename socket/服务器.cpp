//172.16.12.26
#include "winsock2.h"  
#include <string>
#pragma comment(lib, "ws2_32.lib")  //��������lib�� Ҳ����������������
#include<iostream>
using namespace std;
 
//���ݿ����
 
int main()
{
	
	WSADATA         wsd;            //WSADATA����  
	SOCKET          sServer;        //�������׽���  ��������
	SOCKET          sClient;        //�ͻ����׽���  ����
	SOCKADDR_IN     addrServ;;      //��������ַ  
	const int BUF_SIZE = 500;
	char            buf[BUF_SIZE];  //�������ݻ�����  
	char            sendBuf[BUF_SIZE];//���ظ��ͻ��˵�����  
	int             retVal;         //����ֵ  
	//��ʼ���׽��ֶ�̬��  ���뽡׳
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return 1;
	}
 
	//��ʼ���������socket
	//�����׽���  AF_INET��ipv4   SOCK_STREAM��ʹ��tcp
	sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sServer)
	{
		cout << "socket failed!" << endl;
		WSACleanup();//�ͷ��׽�����Դ;  
		return  -1;
	}
 
	//�������׽��ֵ�ַ   
	addrServ.sin_family = AF_INET;//IPv4 
	addrServ.sin_port = htons(4999);//���ö˿� �������1024
	addrServ.sin_addr.s_addr = INADDR_ANY; //��ʾ�����κοͻ��˵�����
 
	//���׽���  �󶨷����socket �� �˿�
	retVal = bind(sServer, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if (SOCKET_ERROR == retVal)
	{
		cout << "bind failed!" << endl;
		closesocket(sServer);   //�ر��׽���  
		WSACleanup();           //�ͷ��׽�����Դ;  
		return -1;
	}
 
	//��ʼ����   
	retVal = listen(sServer, 10);
	if (SOCKET_ERROR == retVal)
	{
		cout << "listen failed!" << endl;
		closesocket(sServer);   //�ر��׽���  
		WSACleanup();           //�ͷ��׽�����Դ;  
		return -1;
	}
 
	//���ܿͻ�������  
	sockaddr_in addrClient;
	int addrClientlen = sizeof(addrClient);
	sClient = accept(sServer, (sockaddr FAR*)&addrClient, &addrClientlen);//ʹ��sClient���������շ�
	if (INVALID_SOCKET == sClient)
	{
		cout << "accept failed!" << endl;
		closesocket(sServer);   //�ر��׽���  
		WSACleanup();           //�ͷ��׽�����Դ;  
		return -1;
	}
 
	while (1)
	{
		//���տͻ�������  
		ZeroMemory(buf, BUF_SIZE);//��ʼ�� buf  �� 0���
		ZeroMemory(sendBuf, BUF_SIZE);
		retVal = recv(sClient, buf, BUF_SIZE, 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "recv failed!" << endl;
			closesocket(sServer);   //�ر��׽���  
			closesocket(sClient);   //�ر��׽���       
			WSACleanup();           //�ͷ��׽�����Դ;  
			return -1;
		}
 
		cout << "set:" << buf << endl;
		//�Կͻ��˵����ݽ��н���
		if (buf[0] == '1')
		{
			cout << "dl" ;
			//��������
			/*
			struct info
			{
			int		flag; ָ��
			char*  username;
			char* password;
			�����ṹ��
				int		flag; ָ��
			}
			*/
		}
		if (buf[0] == '2')
		{
			cout << "zc";
		}
		//��ͻ��˷�������
		cout << "go:";
		cin >> sendBuf;
		send(sClient, sendBuf, strlen(sendBuf), 0);
	}
	
 
	//�ر����� �ͷ���Դ
	closesocket(sServer);   //�ر��׽���  
	closesocket(sClient);   //�ر��׽���  
	WSACleanup();           //�ͷ��׽�����Դ;  
 
	system("pause");
	return 0;
}
 //-static-libgcc
