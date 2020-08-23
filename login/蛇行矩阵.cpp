#include<cstdio>
int main()
{
	int n,a[110][110],i=1,j=1,x,y,num=1,flag=0;
	scanf("%d",&n);
	for(y=1;y<=n;y+=1)
	{
		for(i=1,j=y;i<=n,j>=1;i+=1,j-=1)
		{
			a[j][i]=num;
			num+=1;
		}
	}
	for(y=1;y<=n;y+=1)
	{
		for(x=1;x<=n-y+1;x+=1)
		{
			if(flag==0)
			{
				printf("%d",a[y][x]);
				flag=1;
			}
			else
			{
				printf(" %d",a[y][x]);
			}
		}
		flag=0;
		printf("\n");
	}
}
