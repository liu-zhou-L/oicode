#include<cstdio>
int main()
{
	int a,b;
	for(a=1;a<=9;a+=1)
	{
		for(b=1;b<=a;b+=1)
		{
			printf("%d*%d=%d ",a,b,a*b);
		}
		printf("\n");
	}
}
