#include<cstdio>
int main()
{
	int n,num[101];
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&num[i]);
	}
	for(int i=1;i<=n;i+=1)
	{
		printf("%d ",num[i]);
	} 
}
