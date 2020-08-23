#include<cstdio>
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	if(a<b)
	{
		c=a;
		a=b;
		b=c;
	}
	if(a%b==0)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}
