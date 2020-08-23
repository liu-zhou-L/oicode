#include<cstdio>
int main()
{
	int n,a[1001],b[1001],sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&a[i]);
	} 
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i+=1)
	{
		sum+=a[i]*b[i];
	} 
	printf("%d",sum);
} 
