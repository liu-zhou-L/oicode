#include<cstdio>
int main()
{
	int n,num=0,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		b=1;
		for(int x=1;x<=i;x+=1)
		{
			b*=x;
		}
		num+=b;
	}
	printf("%d",num);
}
