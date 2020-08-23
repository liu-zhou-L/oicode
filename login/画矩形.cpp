#include<cstdio>
int main()
{
	int a,b,d;
	char c;
	scanf("%d %d %c %d",&a,&b,&c,&d);
	for(int i=1;i<=a;i+=1)
	{
		if(d==0)
		{
			if(i==1)
			{
				for(int n=1;n<=b;n+=1)
				{
					printf("%c",c);
				}
			}
			if(i!=1&&i!=a)
			{
				printf("%c",c);
				for(int n=1;n<=b-2;n+=1)
				{
					printf(" ");
				}
				printf("%c",c);
			}
			if(i==a)
			{
				for(int n=1;n<=b;n+=1)
				{
					printf("%c",c);
				}
			}
			printf("\n");
		}
		else
		{
			for(int i=1;i<=b;i+=1)
			{
				printf("%c",c);
			}
			printf("\n");
		}
	}
} 
