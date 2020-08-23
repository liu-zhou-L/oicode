#include<cstdio>
int f(int n)
{
	int num;
	if(n==1)
	{
		return 0;
	}
	num=f(n-1)+n-1;
	return num;
}
int main()
{
	int n,num;
	scanf("%d",&n);
	num=f(n);
	printf("%d",num);
}
