#include<cstdio>
#include<windows.h> 
#include<conio.h> 
#include<time.h>
#include<iostream>
#include"Print.h"
#include"gotoxy.h"
#include"HideCursor.h"
#include"TextColor.h"
#include"Button.h"
#include"Snakeclass.h"
using namespace std;
//������ 
int main() {
	SetConsoleTitle("Snake game");
	system("color 0a");
	HideCursor();//���ع��
	FILE *maxs;//maxs����߷�����ȡָ��	 maxss����߷�������ָ��
	maxs=fopen("C:\\tcs\\data\\maxscore.txt","r");
	if(maxs==NULL) {
		fclose(maxs);
		MessageBox(NULL,"This computer is not installed with snake!","Tips",MB_OK);
		return 0;
	}
	Button play=NewButton(0,0,5,"[Click to start the game]"),Anotherround=NewButton(2,0,5,"[Another round]"),Exit=NewButton(3,0,5,"[Exit]");
	char cd[25][45],flag=0,start,cz,cz2;
	int flag2=0,ddflag=0,dy,dx,ty[100],tx[100],tim,tim2;
	long long maxscore,score,blen;
	system("cls");
	maxs=fopen("C:\\tcs\\data\\maxscore.txt","r");
	fscanf(maxs,"%lld",&maxscore);
	fclose(maxs);
	maxs=fopen("C:\\tcs\\data\\tim.txt","r");
	fscanf(maxs,"%lld",&tim2);
	fclose(maxs);
	while(1) {
		while(1) {
        	if(Preserve(play))
            	break;
            Sleep(20);
    	}
    	system("color 0a");
    	system("cls");
		flag=0;
		score=0;
		blen=5;
		ty[1]=blen;
		tx[1]=1;
		cz = 80;
		tim=200;
		for(int i=1;i<=100;i+=1) {
			if(i<=blen)
				ty[i]=blen-i+1;
			else
				ty[i]=1;
			tx[i]=1;
		}
		TextColor_purple();
		printf("    Snake game");
		for(int i=0;i<=21;i+=1) {
			for(int j=0;j<=41;j+=1) {
				if(i==0&&j==0) {
					gotoxy(i+1,j);
					printf("+");
					cd[i][j]='#';
				}
				else if(i==0&&j==41) {
					gotoxy(i+1,j);
					printf("+");
					cd[i][j]='#';
				}
				else if(i==21&&j==41) {
					gotoxy(i+1,j);
					printf("+");
					cd[i][j]='#';
				}
				else if(i==21&&j==0) {
					gotoxy(i+1,j);
					printf("+");
					cd[i][j]='#';
				}
				else if(i==0||i==21) {
					gotoxy(i+1,j);
					printf("-");
					cd[i][j]='#';
				}
				else if(j==0||j==41){
					gotoxy(i+1,j);
					printf("|");
					cd[i][j]='#';
				}
				else
					cd[i][j]=' ';	
			}	
		}
		gotoxy(1,42);
		printf("maxscore:%lld",maxscore);
		gotoxy(2,42);
		printf("score:%lld",score);
		gotoxy(3,42);
		printf("Esc key exit");
		//cddy(cd,maxscore,score,ty[1],tx[1]);//��ӡ��ͼ 
		TextColor_green();
		for(int i=1;i<=blen;i+=1) {
			if(i==1) {
				gotoxy(ty[i]+1,tx[i]);
				printf("@");
				cd[ty[i]][tx[i]]='@';
			}
			else {
				gotoxy(ty[i]+1,tx[i]);
				printf("*");
				cd[ty[i]][tx[i]]='*';
			}
		}
		while(ty[1]!=0&&tx[1]!=0&&ty[1]!=21&&tx[1]!=41&&cd[ty[1]][tx[1]]!='*') {
			if(ddflag==0) {
				srand((unsigned)time(NULL));
				dy=rand()%20+1;
				srand((unsigned)time(NULL));
				dx=rand()%40+1;
				gotoxy(dy+1,dx);
				printf("$");
				ddflag=1;
			}
			//system("cls");
			gotoxy(ty[1]+1,tx[1]);
			printf("@");
			gotoxy(ty[2]+1,tx[2]);
			printf("*");
			gotoxy(ty[blen]+1,tx[blen]);
			printf(" ");
			cd[ty[1]][tx[1]]='@';
			cd[ty[2]][tx[2]]='*';
			//cddy(cd,maxscore,score,ty[1],tx[1]);//��ӡ��ͼ 
			cd[ty[blen]][tx[blen]]=' ';
			for(int i = blen;i > 1;i -= 1) {
				ty[i] = ty[i - 1];
				tx[i] = tx[i - 1];
			}
			//cz=getch();
			cz2=cz;
			if (_kbhit()) {
				cz = getch();
				tim-=200;
			}
			qj:
    		/*if(cz == ' ') {
    			gotoxy(6,6);
				printf("Pause");
				start = getch();
				gotoxy(6,6);
				printf("     ");
				cz = cz2;
			}//��ͣ 
			else*/ if(75 == cz || cz == 'a')
				tx[1] -= 1;//���� 
			else if(77 == cz || cz == 'd')
				tx[1] += 1;//���� 
			else if(72 == cz || cz == 'w')
				ty[1] -= 1;//���� 
			else if(80 == cz || cz == 's')
				ty[1] += 1;//���� 
			else if(27 == cz) {
				system("cls");
				goto over; 
			}
			else {
				cz=cz2;
				goto qj;
			}
			if(ty[1]==dy&&tx[1]==dx) {
				score+=8;
				blen+=1;
				ddflag=0;
				gotoxy(2,48);
				TextColor_purple();
				printf("%d",score);
				TextColor_green();
				ty[blen]=ty[blen-1];
				tx[blen]=tx[blen-1];
				Beep(2000,100);
				tim-=100;
			}
			Sleep(tim);
			tim=tim2;
		}
		gotoxy(10,10);
		printf("OVER");
		ddflag=0;
		Sleep(1500);
		system("cls");
		TextColor_purple();
		printf("Game over\nscore:%lld",score);
		while(1) {
			if(Preserve(Anotherround)){
				system("color 05");
				system("cls");
				break;
			}
			if(Preserve(Exit)) goto over;
			Sleep(20);
		}
	}
	over:system("cls");
	system("color 05");
	printf("Score saving...");
	if(maxscore<score) {
		maxs=fopen("C:\\tcs\\data\\maxscore.txt","w");
		fprintf(maxs,"%lld",score);
		fclose(maxs);
	}
	system("cls");
	printf("Please wait while you exit...");
	system("cls");
	/*
		MessageBox(����̨����һ��NULL����,"�Ի�������","�Ի������",�Ի�����ʽѡ��);
		MB_OK Ĭ��ֵ����һ��ȷ����
		MB_YESNO ���Ǻͷ�
		MB_ABORTRETRYIGNORE �з��������Ժ�����
		MB_YESNOCANCEL ���ǣ����ȡ��
		MB_RETRYCANCEL �����Ժ�ȡ��
		MB_OKCANCEL ��ȷ����ȡ��
		�����ڲ�ͬ���͵�ֵ֮�����+�ţ�
   		16�����
    	32���ʺ�
    	48����̾��
    	64��Сд��ĸi
    	�����Ǹú����ķ���ֵ��Ϣ��
		ȷ����1
		ȡ����2
		������3
		���ԣ�4
		������5
		�ǣ�6
		��7
		ԭ�����ӣ�https://blog.csdn.net/lengyuezuixue/article/details/79697367
	*/
	MessageBox(NULL,"Exit successfully��","Tips",MB_OK);
	Sleep(500);
	return 0;
}
