#include<cstdio>
int main()
{
	int n,y;
	scanf("%d%d",&n,&y);
	if(y==2)
	{
		if((n%4==0&&n%100!=0)||n%400==0)
		{
			printf("29");
		}
		else
		{
			printf("28");
		}
	}
	else
	{
		if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)
		{
			printf("31");
		}
		if(y==4||y==6||y==9||y==11)
		{
			printf("30");
		}
	}
}
