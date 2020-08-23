#include <cstdio>
#include <stack>
using namespace std;

double num[205];
int index = 0;

int main() {
	double a;
	char b;
	while(scanf("%lf%c", &a, &b)) {
		if(a == 0 && b != ' ') return 0;
		index = 0;
		char l, r;
		double m;
		num[++ index] = a;
		while(scanf("%c %lf%c", &l, &m, &r) != EOF) {
			if (l == '+') {
                num[++ index] = m;
            }
            else if (l == '-') {
                num[++ index] = -m;
            }
            else if (l == '*') {
            	num[index] = num[index] *  m;
            }
            else if (l == '/') {
                num[index] = num[index] / m;
            }
            if(r != ' ') {
                break;
            }
		}
		double count = 0;
        for(int i = 1; i <= index; i ++) {
            count += num[i];
        }
        printf("%.2lf\n",count);
	}
	return 0;
}
/*
#include <stdio.h>
#include <string.h>
 
#define MAX 200
 
double stack[MAX];
int tail;
 
int main()
{
 
    int a;
    while (scanf("%d ",&a) && a!=0)
    {
		tail = 0;
        //a!=0,保存在数组中
        //i 始终指向数字位置
        stack[++tail] = 1.0 * a;
        //入栈其他剩余的数字
        char symbol,space;
        double num;
        while (scanf("%c %lf%c",&symbol,&num,&space)!=EOF)
        {
            if (symbol == '+')
            {
                stack[++tail] = num;//1.0 * num;
            }
            else if (symbol == '-')
            {
                stack[++tail] = -1 * num;//-1.0 * num;
            }
            else if (symbol == '*')
            {
                stack[tail] = stack[tail] * num;
            }
            else if (symbol == '/')
            {
                stack[tail] = stack[tail] / num;
            }
 
            if(space != ' ')
            {
                break;
            }
             
        }
 
        //统计数组中的数值的和
        double count = 0;
        int i;
        for (i=1;i<=tail;i++)
        {
            count += stack[i];
        }
 
        printf("%.2lf\n",count);
 
 
    }
    return 1;
}*/
