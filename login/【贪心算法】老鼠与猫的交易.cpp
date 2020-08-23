#include<cstdio>
#include<algorithm>
using namespace std;
struct stu
{
	double f,j,a;
};
bool cmp(stu x,stu y)
{
	return x.a>y.a;
} 
int main()
{
	stu ni[10005],b;
	int m,n;
	double sum=0;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%lf%lf",&ni[i].j,&ni[i].f);
		ni[i].a=ni[i].j/ni[i].f;
	}
	sort(ni+1,ni+1+n,cmp);
	int i=1;
	for(int i=1;i<=n;i+=1)
	{
		if(ni[i].f>0&&m>=ni[i].f)
		{
			m-=ni[i].f;
			sum+=ni[i].j;
		}
		else
		{
			sum+=ni[i].a*m;
		}
	}
	printf("%.3lf",sum);
	return 0;
}
