#include<cstdio>
int main()
{
	int a,b=0,c=1;
	scanf("%d",&a);
	while(a!=0)
	{
		b+=a%10;
		c*=a%10;
		a/=10;
	}
	printf("%d\n%d",b,c);
}
