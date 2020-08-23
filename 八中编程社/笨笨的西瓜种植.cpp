#include<cstdio>
#include<algorithm>
using namespace std;

int sum = 0;
bool v[5005];

struct conclusion {
	int b, e, t;
} cons[3005];

bool cmp(conclusion i, conclusion j) {
	if (i.e != j.e) return i.e < j.e;
	else return i.b < j.b;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d %d", &cons[i].b, &cons[i].e, &cons[i].t);
	}
	sort(cons + 1, cons + 1 + m, cmp);
	for(int i = 1; i <= m; i ++) {
		for(int j = cons[i].e; j >= cons[i].b; j --) {
			if(cons[i].t > 0 && ! v[j]) {
				v[j] = 1;
				sum ++;
				for(int k = i; k <= m; k ++) {
					if(j >= cons[k].b && j <= cons[k].e) {
						cons[k].t --;
					}
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}
/*
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,v[5010],s;
struct node
{
	int b;//起点
	int e;//末端
	int t;//次数
}a[3010];
bool cmp(node p,node q)//基于sort的判断函数
{
	if(p.e!=q.e) return p.e<q.e;
	else return p.b<q.b;
}
int main()
{
	freopen("watermelon.in","r",stdin);
	freopen("watermelon.out","w",stdout);//文件的读入输出
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)//读入
		scanf("%d%d%d",&a[i].b,&a[i].e,&a[i].t);
	sort(a,a+m,cmp);//排序
	for(i=0;i<m;i++)
	{
		for(j=a[i].e;j>=a[i].b;j--)
			if(a[i].t>0&&!v[j])
			{
				v[j]=1;
				s++;//计数
				for(k=i;k<m;k++)
					if(j>=a[k].b&&j<=a[k].e)
						a[k].t--;
			}
	}
	printf("%d",s);//输出答案
}*/
