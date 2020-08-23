#include<cstdio>
int main()
{
	int n,a[100000]={0},num=0,b;
	scanf("%d",&n);
	for(int i=0;i<n;i+=1)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i+=1)
	{
		if(a[i]==i)
		{
			num+=1;
			i+=1;
		}
	}
	printf("%d",num);
}
