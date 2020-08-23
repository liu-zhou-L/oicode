#include<cstdio>
int main()
{
	int a,b,c,d;
	scanf("%d",&a);
	d=(a-1)*2+1;
	for(int i=1;i<=d;i+=2)
	{
		c=(d-i)/2;
		b=i;
		for(;c>0;c-=1)
		{
			printf(" ");
		}
		for(;b>0;b-=1)
		{
			printf("*");
		}
		printf("\n");
	}
}
