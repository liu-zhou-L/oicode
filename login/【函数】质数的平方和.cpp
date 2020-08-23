#include<cstdio>
int p(int n)
{
	if(n==1) return false;
	for(int i=2;i*i<=n;i+=1)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int a,b,flag=0,num=0;
	scanf("%d%d",&a,&b);
	for(int n=a;n<=b;n+=1)
	{
		flag=0;
		flag=p(n);
		if(flag==1)
		{
			num+=n*n;
		}
	}
	printf("%d",num);
}
