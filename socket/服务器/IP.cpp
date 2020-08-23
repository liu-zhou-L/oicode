#ifndef CMDEXC_H 
#define CMDEXC_H 
#include <string> 
#include <WinSock2.h>
#include <cstdio>
class CmdExc 
{ 
public: CmdExc(std::string cmd,std::string mode="rt"); 
virtual ~CmdExc(); std::string getOutput() const; 
private: std::string m_strOutput__; FILE* m_fp__; 
}; 
CmdExc::CmdExc(std::string cmd, std::string mode) 
{ m_fp__=_popen(cmd.c_str(),mode.c_str()); 
char buf[256]={0}; 
if(NULL != m_fp__)
{ int read_len; 
while((read_len=fread(buf,sizeof(buf)-1,1,m_fp__))>0)
{ m_strOutput__+=buf; memset(buf,0,sizeof(buf)); } } } 
CmdExc::~CmdExc() 
{ 
if(NULL != m_fp__)
{ _pclose(m_fp__); 
} 
} 
std::string CmdExc::getOutput() const { return m_strOutput__; } 
#endif // CMDEXC_H
