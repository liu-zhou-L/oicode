#include<iostream>
#include"IP.h"
using namespace std;
int main()
{
       CmdExc cmd("ipconfig");
	cout<<cmd.getOutput().c_str()<<endl;
    return 0;
}

