#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <Iphlpapi.h>
#include <iostream>
using namespace std;
#pragma comment(lib,"Iphlpapi.lib") //��Ҫ���Iphlpapi.lib��
#pragma comment(lib, "ws2_32.lib")
 
int new_fd = accept(sock, &clientAddr, &sin_size);
if(new_fd<0)
{
char msg[64];
bzero(msg,sizeof(msg));
sprintf(msg,"accept failed");
log::outputSysErr(msg);
}
else
{
// ��sockaddrǿ��ת��Ϊ sockaddr_in
sockaddr_in sin;
memncpy(&sin, &clientAddr, sizoef(sin));
// ȡ��ip�Ͷ˿ں�
sprintf(info.ip, inet_ntoa(sin.sin_addr));
info.port = sin.sin_port;
info.sock = new_fd;
}
