#include<cstdio>
int main()
{
	int n,m,flag=0;
	bool d[5001];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i+=1)
	{
		d[i]=1;
	}
	for(int i=1;i<=m;i+=1)
	{
		for(int x=1;x<=n;x+=1)
		{
			if(x%i==0)
			{
				d[x]=!d[x];
			} 
		}
	}
	for(int i=1;i<=n;i+=1)
	{
		if(d[i]==0)
		{
			if(flag!=1)
			{
				printf("%d",i);
			}
			else
			{
				printf(",%d",i);
			}
			flag=1;
		}
	} 
	printf("\n");	
}
