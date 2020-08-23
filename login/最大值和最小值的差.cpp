#include<cstdio>
int main()
{
	int a,b[10000],c=-10000,d=10000,i,n;
	scanf("%d",&a);
	for(i=1;i<=a;i+=1)
	{
		scanf("%d",&b[i]);
	}
	for(n=1;n<=a;n+=1)
	{
		if(b[n]>c)
		{
			c=b[n];
		}
		if(b[n]<d)
		{
			d=b[n];
		}
	}
	printf("%d",c-d);
	return 0;
}

