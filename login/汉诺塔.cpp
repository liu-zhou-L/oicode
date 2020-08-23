#include<cstdio>
long long f(int n)
{
	long long num=0;
	if(n==1)
	{
		return 1;
	}
	num+=2*f(n-1)+1;
	return num;
}
int main()
{
	long long n,a;
	scanf("%lld",&n);
	a=f(n);
	printf("%lld",a);
}
