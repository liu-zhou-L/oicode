#include<cstdio>
int a[60];
int main()
{
	int n;
	scanf("%d",&n);
	a[0]=1;
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=n;i+=1)
	{
		a[i]=a[i-1]+a[i-2];
	}
	printf("%d",a[n]);
	return 0; 
}
