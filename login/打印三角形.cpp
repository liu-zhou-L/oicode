#include<cstdio>
int main()
{
	int a,b;
	scanf("%d",&a);
	for(int i=1;i<=a;i+=1)
	{
		b=i;
		for(;b>0;b-=1)
		{
			printf("*");
		}
		printf("\n");
	}
}
