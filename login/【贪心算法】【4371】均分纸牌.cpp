#include<cstdio>
int a[105];
int main()
{
	int n,sum=0,s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sum/=n;
	for(int i=1;i<=n;i+=1)
	{
		if(a[i]<sum)
		{
			a[i+1]-=sum-a[i];
			a[i]=sum;
			s+=1;
		}
		else if(a[i]>sum)
		{
			a[i+1]+=a[i]-sum;
			a[i]=sum;
			s+=1;
		}
	}
	printf("%d",s);
	return 0;
}
