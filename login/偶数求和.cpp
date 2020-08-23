#include<cstdio>
int main()
{
	int a,b,num=0;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i+=1)
	{
		if(i%2==0)
		{
			num+=i;
		}
	}
	printf("%d",num);
} 
