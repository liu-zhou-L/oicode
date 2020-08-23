#include<cstdio>
#include <stdlib.h>
#include <windows.h> 
#include <conio.h> 
#include <time.h> 
void cdcsh()
{
	system("color 0a");
	int x=1,y=1;
	for(;y<=15;y+=1)
	{
		for(x=1;x<=15;x+=1)
		{
			if((y==1||y==15)&&x>1&&x<15)
			{
				printf("¨T");
			}
			else if((x==1||x==15)&&y>1&&y<15)
			{
				printf("¨U");
			}
			else if(x==1&&y==1)
			{
				printf("¨X");
			}
			else if(x==15&&y==15)
			{
				printf("¨a");
			}
			else if(x==15&&y==1)
			{
				printf("¨[");
			}
			else if(x==1&&y==15)
			{
				printf("¨^");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}
int main()
{
	cdcsh();
}
