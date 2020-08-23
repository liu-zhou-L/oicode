#include<cstdio>
int A(int a,int b)
{
	int n=1;
	for(int i=a;a>i-b;a-=1)
	{
		n*=a;
	}
	return n;
}
int main()
{
	int a,b,num;
	scanf("%d%d",&a,&b);
	num=A(a,b);
	printf("%d",num);
}
