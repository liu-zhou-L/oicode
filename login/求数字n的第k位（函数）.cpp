#include<cstdio>
int digit(int n,int k)
{
	for(;k>1;k-=1)
	{
		n/=10;
	}
	n%=10;
	return n;
}
int main()
{
	int m,a[110],n,k,num;
	scanf("%d",&m);
	for(;m>0;m-=1)
	{
		scanf("%d%d",&n,&k);
		num=digit(n,k);
		printf("%d\n",num);
	}
}
