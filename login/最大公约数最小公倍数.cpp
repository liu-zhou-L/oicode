#include<cstdio>
int main()
{
	long long a,b,c,d,e;
	scanf("%lld%lld",&a,&b);
	d=a;e=b;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	printf("%lld %lld",a,d/a*e/a*a);
} 
