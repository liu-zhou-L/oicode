#include <windows.h>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<windows.h>
#include <iostream>
using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
//��Ҫ��������ʲô
void gotoxy(int y, int x)
{
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    // COORD cursorPosition = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}
void TextColor_Green()
{    
      HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(Handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
}
void TextColor_red()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//���ú�ɫ
}
void TextColor_green()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//������ɫ
}
void TextColor_blue()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//������ɫ
}
void TextColor_yellow()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//���ú�ɫ����ɫ���
}
void TextColor_pink()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//���ú�ɫ����ɫ���
}
void TextColor_qingse()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);//������ɫ����ɫ���
}
struct Button{//��ť����
    int x,y,color;//��ťλ�ú���ɫ
    const char *name;//����
    int len;//���ֵĳ���
};

void GetPos(POINT &pt){//�������������Ļ��λ��
//POINT���Դ�����
    HWND hwnd=GetForegroundWindow();
    GetCursorPos(&pt);
    ScreenToClient(hwnd,&pt);
    pt.y=pt.y/16,pt.x=pt.x/16;//����16���벻�����Լ�����ȥ������
}

void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}
//�޸���ɫ
//��֪��ÿ����ɫ�Ĵ����forѭ��1��256����
void gto(int x,int y)//�����ֵĹ���Ƶ�x��y��
{
    COORD pos;pos.X=y*2;pos.Y=x;
    //���뷴����
    //y*2����Ϊ������2���ַ�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

Button NewButton(int x,int y,int color,const char *name){
    Button t;
    t.x=x,t.y=y,t.name=name;
    t.color=color;
    t.len=strlen(name);
    return t;//�½���ť��������
}

bool Preserve(Button A){
    //ά��һ����ť
    //���Ҫʹ��������ñ�����ѭ���в���ִ����
    //��������ʾ��
    gto(A.x,A.y),color(A.color),printf("%s",A.name);
    POINT pt;
    GetPos(pt);
    if(pt.y==A.x&&(pt.x>=A.y&&pt.x<=A.y+A.len/2)){
        color(A.color+16),gto(A.x,A.y),printf("%s",A.name);
        if(KEY_DOWN(MOUSE_MOVED)) return 1;//��⵽�����ť
    }
    return 0;//û�м�⵽
}
