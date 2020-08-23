#include<cstdio>
int main()
{
	int n,num[1001],x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&num[i]);
	}
	scanf("%d%d",&x,&y);
	for(int i=n+1;i>x;i-=1)
	{
		num[i]=num[i-1];
	}
	num[x]=y;
	for(int i=1;i<=n+1;i+=1)
	{
		printf("%d ",num[i]);
	}
}
