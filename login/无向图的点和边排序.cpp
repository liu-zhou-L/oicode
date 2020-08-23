#include<cstdio>
#include<algorithm>
using namespace std;
struct e1{
	int n,eg;
}b[1005];
struct e2{
	int i,j,eg;
}a[1005];
bool cmp1(e1 i,e1 j) {
	return i.eg>j.eg;
}
bool cmp2(e2 i,e2 j) {
	return i.eg<j.eg;
}
int e2num=0;
int main() {
	int n,m,u,w,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) b[i].n=i; 
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		e2num++;
		a[e2num].i=u;
		a[e2num].j=v;
		a[e2num].eg=w;
		b[u].eg++;
		b[v].eg++;
	}
	sort(b+1,b+1+n,cmp1);
	sort(a+1,a+1+m,cmp2);
	for(int i=1;i<=n;i++) {
		printf("%d\n",b[i].n);
	}
	for(int i=1;i<=m;i++) {
		printf("%d %d %d\n",a[i].i,a[i].j,a[i].eg);
	}
	return 0;
}
