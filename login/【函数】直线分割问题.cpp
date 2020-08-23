#include<cstdio>
int f(int n)
{
	int num;
	if(n==0)
	{
		return 1;
	}
	num=f(n-1)+n;
	return num;
}
int main()
{
	int n,num;
	scanf("%d",&n);
	num=f(n);
	printf("%d",num);
}
