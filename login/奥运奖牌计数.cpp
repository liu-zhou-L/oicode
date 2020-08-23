#include<cstdio>
int main()
{
	int n,numj=0,numy=0,numt=0,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&b);
		numj+=b;
		scanf("%d",&b);
		numy+=b;
		scanf("%d",&b);
		numt+=b;
	}
	printf("%d %d %d %d",numj,numy,numt,numj+numy+numt);
}
