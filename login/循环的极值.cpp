#include<cstdio>
int main()
{
	int n,a[100005],max=-999999999,max2=-999999999;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&a[i]);
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	for(int i=1;i<=n;i+=1)
	{
		if(a[i]>max2&&a[i]<max)
		{
			max2=a[i];
		}
	}
	printf("%d",max2);
	return 0;
}
