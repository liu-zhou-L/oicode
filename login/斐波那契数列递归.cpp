#include<cstdio>
int f(int n)
{
	int ret;
	if(n==1||n==2) return 1;
	else
	{
		ret=f(n-1)+f(n-2);
		return ret;
	}
}
int main()
{
	int n,a;
	scanf("%d",&n);
	a=f(n);
	printf("%d",a); 
}
