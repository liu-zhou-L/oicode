#include<cstdio>
int main()
{
	int n;
	long long a[100005],sum=0,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i+=1)
	{
		b=a[i];
		a[i]=0;
		sum+=b>0?b:-b;
		a[i+1]+=b;
	}
	printf("%lld",sum);
	return 0;
} 
