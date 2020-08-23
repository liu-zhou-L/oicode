#include<cstdio>
void f(int n)
{
	int sum=1;
	for(int i=1;i<=n;i+=1)
	{
		sum*=i;
	}
	printf("%d",sum);
}
int main()
{
	int n;
	scanf("%d",&n);
	f(n);
} 
