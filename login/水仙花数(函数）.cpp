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
	int a,sum;
	scanf("%d",&a);
	for(int i=100;i<=a;i+=1)
	{
		sum=pow(i%10,3)+pow(i/10%10,3)+pow(i/100,3);
		if(sum==i)
		{
			printf("%d\n",i);
		}
	}
}
