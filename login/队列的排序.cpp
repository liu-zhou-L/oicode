#include<cstdio>
int a[1000000];
int main()
{
	int n,t;
	scanf("%d",&n);
	a[1000000]={0};
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&t);
		a[t]++;
	}
	for(int i=1;i<=1000000;i+=1)
	{
		for(int n=1;n<=a[i];n+=1)
		{
			printf("%d ",i);
		} 
	} 
} 
