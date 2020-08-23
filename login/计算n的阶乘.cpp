#include<cstdio>
int fac(int n)
{
	int ret;
	if(n==0)
	{
		return 1;
	}
	else
	{
		ret=fac(n-1);
		return ret*n;
	}
}
int main()
{
	int n,a;
	scanf("%d",&n);
	a=fac(n);
	printf("%d",a);
}
