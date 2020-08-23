#include<cstdio>
int main()
{
	long long a,b[100],c=-1000000,d=0;
	scanf("%lld",&a);
	for(int i=1;i<=a;i+=1)
	{
		scanf("%lld",&b[i]);
		if(b[i]>c)
		{
			c=b[i];
		}
	}
	for(int n=1;n<=a;n+=1)
	{
		d+=b[n];
	}
	printf("%lld",d-=c);
}
