#include<cstdio>
int main()
{
	int a,n;
	double b[10001],c;
	scanf("%d",&a);
	for(int i=1;i<=a;i+=1)
	{
		scanf("%lf",&b[i]);
	}
	scanf("%lf",&c);
	for(n=1;n<=a;n+=1)
	{
		if(b[n]==c)
		{
			break;
		}
	}
	printf("%d",n);
	return 0; 
}
