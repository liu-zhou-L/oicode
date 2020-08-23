#include<cstdio>
int main()
{
	int m,p,a;
	scanf("%d%d",&m,&p);
	a=2*p;
	for(int i=p+1;i<=m;i+=1)
	{
		a=a+i;
	}
	printf("%d",a);
} 
