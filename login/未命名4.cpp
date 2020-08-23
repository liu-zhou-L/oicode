#include<cstdio>
long long gcd(long long  a,long long  b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	long long a,b,gcd1,gcd2,i;
	scanf("%lld%lld",&a,&b);
	if(a>b)
	{
		i=a;
	}
	else
	{
		i=b;
	}
	for(;;i+=1)
	{
		if(i%a==0&&i%b==0)
		{
			gcd2=i;
			break;
		}
	}
	gcd1=gcd(a,b);
	printf("%lld %lld",gcd1,gcd2);
	
}
