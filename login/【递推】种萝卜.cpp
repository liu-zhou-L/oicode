#include<cstdio>
long long a[80];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	a[0]=1;
	for(int i=1;i<=n;i+=1)
	{
		if(i<m)
			a[i]=2*a[i-1];
		else if(i==m)
			a[i]=2*a[i-1]-1;
		else
			a[i]=2*a[i-1]-a[i-m-1];
	}
	printf("%lld",a[n]);
	return 0;
}
