#include "winsock2.h"  
#include <string>
#include <iostream>  
#pragma comment(lib, "ws2_32.lib")
 
using namespace std;
 
int main()
{
	WSADATA wsd; //WSADATA����  
	SOCKET sHost; //�ͻ����׽���  
	SOCKADDR_IN servAddr; //��������ַ  
 
	const int BUF_SIZE = 500;
	char buf[BUF_SIZE]; //�������ݻ�����  
	char bufRecv[BUF_SIZE];
	int retVal; //����ֵ  
	//��ʼ���׽��ֶ�̬�� 
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return -1;
	}
	//�����׽���  
	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sHost)
	{
		cout << "socket failed!" << endl;
		WSACleanup();//�ͷ��׽�����Դ  
		return  -1;
	}
	servAddr.sin_family = AF_INET;
	//�������ͨ���� ���� c++ ����  sdl �ĳɷ�
	char inte[20];
	scanf("%s",inte);
	servAddr.sin_addr.s_addr = inet_addr(inte);//���÷���˵�ַ  �����ʾ����
	servAddr.sin_port = htons((short)4999);
	int nServAddlen = sizeof(servAddr);
 
	//���ӷ�����  
	retVal = connect(sHost, (LPSOCKADDR)&servAddr, sizeof(servAddr));
	if (SOCKET_ERROR == retVal)
	{
		cout << "connect failed!" << endl;
		closesocket(sHost); //�ر��׽���  
		WSACleanup(); //�ͷ��׽�����Դ  
		return -1;
	}
	//�ɹ���������  ���Կ�ʼͨ����
	while (1)
	{
		//���������������  
		ZeroMemory(buf, BUF_SIZE);
		cout << "go:";
		cin >> buf;
		// ��װ���ݣ�   ָ���� ��  ����
		//						1-100 
		//						1:��¼  username - passeord 2��ע��  3 ��ѯ  4 �������ݿ� 5 .....
		/*
			struct info
			{
				int		flag; ָ��
				char*  username;
				char* password;
				�����ṹ��
			}
			
		*/
		retVal = send(sHost, buf, strlen(buf), 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "send failed!" << endl;
			closesocket(sHost); //�ر��׽���  
			WSACleanup(); //�ͷ��׽�����Դ  
			return -1;
		}
		ZeroMemory(bufRecv, BUF_SIZE);
		recv(sHost, bufRecv, BUF_SIZE, 0); // ���շ������˵�����
		cout << endl << "set:" << bufRecv;
		cout << "\n";
	}
	
 
	closesocket(sHost); //�ر��׽���  
	WSACleanup(); //�ͷ��׽�����Դ  
	system("pause");
	return 0;
}
