#include<cstdio>
int abs(int a,int b)
{
	int c;
	c=a-b;
	if(c<0)
	{
		c=-c;
	}
	return c;
}
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=abs(a,b);
	printf("%d",c);
}
