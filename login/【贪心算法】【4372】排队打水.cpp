#include<cstdio>
#include<algorithm>
using namespace std;
int a[505],te[505];
int main()
{
	int n,r,times=0;
	scanf("%d %d",&n,&r);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;i+=1)
	{
		te[j]+=a[i];
		times+=te[j];
		j++;
		if(j>r) j=1;
	}
	printf("%d",times);
	return 0;
}
