#include<cstdio>
int main()
{
	int n,a[20001],b[20001],flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	} 
	for(int i=1;i<=n;i+=1)
	{
		flag=0;
		for(int u=1;u<i;u+=1) 
		{
			if(a[u]==a[i])
			{
				flag=1;
			} 
		}
		if(flag==0)
		{
			printf("%d ",a[i]);
		}
	}
	 
}
