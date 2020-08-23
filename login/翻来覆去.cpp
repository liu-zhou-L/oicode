#include<cstdio>
int a[1000010];
int main()
{
	int n,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&a[i]);
	}
	if(n%2==0)
	{
		for(int i=n;i>0;i-=2)
		{
			printf("%d ",a[i]);
		}
		for(int i=1;i<=n;i+=2)
		{
			printf("%d ",a[i]);
		}
	}
	else
	{
		for(int i=n;i>0;i-=2)
		{
			printf("%d ",a[i]);
		}
		for(int i=2;i<=n;i+=2)
		{
			printf("%d ",a[i]);
		}
	}
}
