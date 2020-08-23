#include<cstdio>
int main()
{
	int a,b[101];
	scanf("%d",&a);
	for(int i=1;i<=a;i+=1)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=a;i+=1)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	for(int i=1;i<=a;i+=1)
	{
		if(b[i]%2==1)
		{
			printf("%d ",b[i]);
		}
	}
	printf("\n"); 
	for(int i=1;i<=a;i+=1)
	{
		if(b[i]%2==0)
		{
			printf("%d ",b[i]);
		}
	} 
} 
