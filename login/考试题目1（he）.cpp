#include<cstdio>
int c[]
int main()
{
	int n,a,b[100010]={0},e=0;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i+=1)
	{
		scanf("%d",&a);
		b[a]+=1;
		if(a>e)
		{
			e=a;
		}
	}
	for(int i=1;i<=e;i+=1)
	{
		if(b[i]!=2)
		{
			printf("%d",i);
		}
	}
}
