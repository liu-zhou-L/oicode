#include<cstdio>
int main()
{
	int n,max=0,min=10000000000,max2,min2;
	double a[310],max1=0,num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%lf",&a[i]);
		num+=a[i];
		if(a[i]<min)
		{
			min=a[i];
			min2=i;
		}
		if(a[i]>max)
		{
			max=a[i];
			max2=i;
		}
	}
	num-=min+max;
	num/=n-2;
	for(int i=1;i<=n;i+=1)
	{
		if(i!=max&&i!=min)
		{
			if(a[i]>num)
			{
				max1=a[i]-num;
			}
			if(a[i]<num)
			{
				max1=num-a[i];
			}
		}
	}
	printf("%.2lf %.2lf",num,max1);
}
