#include<cstdio>
int main()
{
	int a[1001],i=1,b=0,c=0;
	while(scanf("%d", &a[i]) ==1)
	{
		i+=1;
	}
	a[i+1]=a[1];
	a[i+2]=a[2];
	a[i+3]=a[3];
	for(int n=1;n<=i;n+=1)
	{
		if(a[n]+a[n+1]+a[n+2]+a[n+3]>b)
		{
			b=a[n]+a[n+1]+a[n+2]+a[n+3];
			c=n;
		}
	}
	printf("%d %d",c,b);
}
