#include<cstdio>
void q(int a,int b)
{
	int num1=0,num2=0;
	for(int i=a;i<=b;i+=1)
	{
		num2=0;
		for(int n=1;n<i;n+=1)
		{
			if(i%n==0)
			{
				num2+=n;
			}
		}
		if(num2<i)
		{
			num1+=1;
		}
	}
	printf("%d",num1);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	q(a,b);
}
