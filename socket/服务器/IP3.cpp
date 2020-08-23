#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <Iphlpapi.h>
#include <iostream>
using namespace std;
#pragma comment(lib,"Iphlpapi.lib") //需要添加Iphlpapi.lib库
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
// 将sockaddr强制转换为 sockaddr_in
sockaddr_in sin;
memncpy(&sin, &clientAddr, sizoef(sin));
// 取得ip和端口号
sprintf(info.ip, inet_ntoa(sin.sin_addr));
info.port = sin.sin_port;
info.sock = new_fd;
}
