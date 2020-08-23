#include<cstdio>
int main()
{
	int a,b=0;
	scanf("%d",&a);
	while(a!=0)
	{
		b*=10;
		b+=a%10;
		a/=10;
	}
	printf("%d",b);
}
