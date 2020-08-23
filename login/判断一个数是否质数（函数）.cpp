#include<cstdio>
bool p(int n)
{
	for(int i=2;i*i<=n;i+=1)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	bool res;
	scanf("%d",&n);
	res=p(n);
	if(res==false)
	{
		printf("false");
	}
	else
	{
		printf("true");
	}
}
