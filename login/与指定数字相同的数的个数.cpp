#include<cstdio>
int main()
{
	int n,num[101],x,a=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&num[i]);
	}
	scanf("%d",&x);
	for(int i=1;i<=n;i+=1)
	{
		if(num[i]==x)
		{
			a+=1;
		} 
	}
	printf("%d",a);
}
