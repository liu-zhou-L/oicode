#include<cstdio>
#include<cmath>
int main()
{
	int a[3007];
	int b[3007];
	int n,t,flag = 1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(int i=1;i<=n-1;i++)
	{
		b[i]=fabs(a[i]-a[i+1]);
	}
	n--;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(b[i]>b[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i != b[i])
		{
			flag=0;
			break;
		} 
	}
	if(flag==1)
		printf("Jolly\n");
	else
		printf("Not jolly\n");
	return 0;
} 
