#include<cstdio>
int main()
{
	int n,a[50];
	scanf("%d",&n);
	a[1]=1;
	a[2]=2;
	a[3]=4;
	for(int i=4;i<=n;i+=1)
	{
		a[i]=a[i-1]+a[i-2]+a[i-3];
	}
	printf("%d",a[n]);
	return 0; 
}
