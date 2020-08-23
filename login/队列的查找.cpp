#include<cstdio>
int a[10005];
int main(){
	int n,num,flag=0,x,s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);
	for(int i=1;i<=n;i+=1)
	{
		if(a[i]==x)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==x)
			{
				continue;
			} 
			printf("%d ",a[i]);
		}
	} 
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>x&&s==0)
			{
				printf("%d ",x);
				s++;
			} 
			printf("%d ",a[i]);
		}
		if(x>a[n])
		{
			printf("%d",x);
		}
	 }
} 
