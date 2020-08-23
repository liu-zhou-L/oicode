#include<cstdio>
void q(int a,int b)
{
	int anum=0,bnum=0;
	for(int i=1;i<a;i+=1)
	{
		if(a%i==0)
		{
			anum+=i;
		}
	}
	for(int i=1;i<b;i+=1)
	{
		if(b%i==0)
		{
			bnum+=i;
		}
	}
	if(bnum==a&&anum==b)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	q(a,b);
}
