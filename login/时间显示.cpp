#include<cstdio>
#include<windows.h> 
#include<time.h> 
int main() 
{
	int a,b=0,s,m,h;
	while(1)
	{
		b=time(NULL);
		s=b%60;
		m=b/60%60;
		h=b/3660%24+7;
		if(h<10) printf("0");
		printf("%d:",h);
		if(m<10) printf("0");
		printf("%d:",m);
		if(s<10) printf("0");
		printf("%d",s);
		Sleep(999);
		system("cls");
	} 
}
