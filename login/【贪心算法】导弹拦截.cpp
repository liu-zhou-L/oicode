#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct node
{
	int dis1,dis2; 
}a[MAXN];
bool cmp(node x,node y)
{
	return x.dis1<y.dis1;
} 
int main()
{
	int x1,y1,x2,y2,n,x,y;
	scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		a[i].dis1=(x1-x)*(x1-x)+(y1-y)*(y1-y);
		a[i].dis2=(x2-x)*(x2-x)+(y2-y)*(y2-y);
	}
	sort(a,a+n,cmp);
	int ans=1e9,cost=0;
	a[n].dis2=0;
	for(int i=n-1;i>=0;--i)
	{
		cost=max(cost,a[i+1].dis2);
		ans=min(ans,a[i].dis1+cost);
	}
	cost=max(cost,a[0].dis2);
	ans=min(ans,cost);
	printf("%d",ans);
	return 0;
}
