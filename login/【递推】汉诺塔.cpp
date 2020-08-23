#include<cstdio>
long long a[80];
int main()
{
	int n;
	scanf("%d",&n);
	a[1]=1;
	for(int i=2;i<=n;i+=1)
	{
		a[i]=a[i-1]*2+1;
	}
	printf("%lld",a[n]);
}
