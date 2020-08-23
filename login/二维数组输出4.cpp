#include<cstdio>
int main()
{
	int n,a[10][10],num=1;
	bool flag=1,flag2=0;//1ÏòÓÒ,0Ïò×ó 
	scanf("%d",&n);
	for(int y=0;y<=n-1;y+=1)
	{
		if(flag==1)
		{
			for(int x=0;x<=n-1;x+=1,num+=1)
			{
				a[y][x]=num;
			}
		}
		if(flag==0)
		{
			for(int x=n-1;x>=0;x-=1,num+=1)
			{
				a[y][x]=num;
			}
		}
		flag=!flag;
	}
	for(int y=0;y<=n-1;y+=1)
	{
		for(int x=0;x<=n-1;x+=1)
		{
			if(flag2==0)
			{
				printf("%d",a[y][x]);
				flag2=1;
			}
			else
			{
				printf(" %d",a[y][x]);
			}		
		}
		flag2=0;
		printf("\n");
	} 
} 
