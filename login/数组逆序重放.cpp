#include<cstdio>
int main()
{
	int a,b[101];
	scanf("%d",&a);
	for(int i=1;i<=a;i+=1)
	{
		scanf("%d",&b[i]);
	}
	for(int i=a;i>0;i-=1)
	{
		printf("%d ",b[i]);
	}
}
