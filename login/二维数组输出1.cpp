#include<cstdio>
int main()
{
	int n,a[10][10],num=1,flag=0;
	scanf("%d",&n);
	for(int x=0;x<=n-1;x+=1)
	{
		for(int y=0;y<=n-1;y+=1)
		{
			a[x][y]=num;
			num+=1;
		} 
	}
	for(int x=0;x<=n-1;x+=1)
	{
		for(int y=0;y<=n-1;y+=1)
		{
			if(flag==0)
			{
				printf("%d",a[x][y]);
				flag=1;
			}
			else
			{
				printf(" %d",a[x][y]);
			} 
		}
		printf("\n");
		flag=0;
	}
} 
