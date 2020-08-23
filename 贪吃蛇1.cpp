#include<cstdio>
#include<windows.h> 
#include<conio.h> 
#include<time.h>
#include<iostream>
using namespace std;
int main()
{
	system("color 0a");
	char cd[101][101],cz,flag=0;
	int ty[100]={1},tx[100]={0},tcs=0,maxscore=0,y=1,x=1,flag2=0,flag3=0,dy,dx;
	ty[1]={1};
	tx[1]={1};
	while(1)
	{
		flag=0;
		tcs=5;
		y=1;
		x=1;
		for(int i=2;i<=100;i+=1)
		{
			ty[i]=0;
			tx[i]=0;
		}
		ty[1]={1};
		tx[1]={1};
		while(cd[y][x]!='#'&&cd[y][x]!='*')
		{
			if(flag3==0)
			{
				srand((unsigned)time(NULL));
				dy=rand()%20+1;
				srand((unsigned)time(NULL));
				dx=rand()%20+1;
				flag3=1;
			}
			system("cls");
			for(int i=0;i<=21;i+=1)
			{
				for(int j=0;j<=21;j+=1)
				{
					if(i==0||j==0||i==21||j==21) 
						cd[i][j]='#';	
					else
						cd[i][j]=' ';
				}	
			}
			for(int i=1;i<=tcs;i+=1)
			{
				if(i==1)
					cd[ty[i]][tx[i]]='@';
				else
					cd[ty[i]][tx[i]]='*';
			}
			cd[dy][dx]='!';
			for(int y=0;y<=21;y+=1)
			{
				for(int x=0;x<=21;x+=1)
					printf("%c",cd[y][x]);
				if(y==0)
					printf("maxscore:%d",maxscore);
				if(y==1)
					printf("score:%d",tcs-5);
				printf("\n");
			}			
			for(int i=tcs;i>1;i-=1)
			{
				ty[i]=ty[i-1];
				tx[i]=tx[i-1];
			}
			cz=getch();
			if(cz=='a')
				x-=1;
			if(cz=='d')
				x+=1;
			if(cz=='w')
				y-=1;
			if(cz=='s')
				y+=1;
			tx[1]=x;
			ty[1]=y;
			if(cd[ty[1]][tx[1]]=='!')
			{
				tcs+=1;
				flag3=0;
			}
		}
		printf("OVER");
		Sleep(1500);
		if(maxscore<tcs-5)
			maxscore=tcs-5;
		system("cls");
		printf("游戏结束\nscore:%d\n按任意键再来一局",tcs-5);
		flag=getch();
		system("cls");
	}
}
