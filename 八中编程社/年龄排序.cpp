#include<cstdio>
#include<algorithm>
using namespace std;
struct stu{
	int y,m;
	char name[30],xb[10];
};
bool cmp(stu i,stu j) {
	if(i.y!=j.y) return i.y>j.y;
	else return i.m>j.m;
}
stu a[105];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s %s %d %d",&a[i].name,&a[i].xb,&a[i].y,&a[i].m);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) {
		printf("%s %s %d %d\n",a[i].name,a[i].xb,a[i].y,a[i].m);
	}
	return 0;
}
