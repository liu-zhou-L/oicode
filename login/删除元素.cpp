#include<cstdio>
int main()
{
	int n,ai[100001],x;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&ai[i]);
	}
	scanf("%d",&x);
	for(int i=1;i<=n;i+=1)
	{
		if(i!=x)
		{
			printf("%d ",ai[i]);
		}
	}
}
