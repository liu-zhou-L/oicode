#include<cstdio>
#include<algorithm>
using namespace std;
struct f
{
	int ti,mi; 
};
bool flag[1005];
bool cmp(f x,f y)
{
	return x.mi>y.mi;
}
bool cheak(int z)
{
	for(int i=z;i>=1;--i)
	{
		if(!flag[i])
		{
			flag[i]=1;
			return true;
		}
	}
	return false;
}
int main()
{
	int n,sum=0;
	f a[105];
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d%d",&a[i].ti,&a[i].mi);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i+=1)
	{
		if(!cheak(a[i].ti)) sum+=a[i].mi;
	}
	printf("%d",sum);
	return 0;
} 
