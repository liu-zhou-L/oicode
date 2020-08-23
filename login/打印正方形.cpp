#include<cstdio>
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i+=1)
	{
		for(int n=1;n<=a;n+=1)
		{
			printf("*");
		}
		printf("\n");
	}
} 
