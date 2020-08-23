#include<cstdio>
int pow(int a,int b)
{
	int c=1;
	for(int i=1;i<=b;i+=1)
	{
		c*=a;
	}
	return c;
}
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=pow(a,b);
	printf("%d",c);
}
