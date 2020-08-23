#include<cstdio>
int f(int a)
{
	if(a/100!=0)
	{
		if(a%10==a/100)
			return 1;
	}
	else
	{
		if(a%10==a/10)
			return 1;
	}
	return 0;
}
int main()
{
	int i,n=0,a=11,b,c;
	bool flag=0;
	for(a=11;a<=999;a+=1)
	{
		b=a*a;
		c=a*a*a;
		if(f(a)==1)
		{
			if(f(b)==1) 
			{
				if(f(c)==1)
				{
					printf("%d ",a);				
				}
			}
		}
	} 
} 
