#include<cstdio>
#include<algorithm>
using namespace std;
struct stu{
	int id,score;
}a[5005];
bool cmp(stu i,stu j) {
	if(i.score!=j.score) return i.score>j.score;
	else return i.id<j.id;
}
int main() {
	int n,m,mi,nums=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i].id,&a[i].score);
	}
	sort(a+1,a+1+n,cmp);
	mi=a[int(m*1.0/2*3)].score;
	for(int i=1;i<=n;i++) {
		if(a[i].score>=mi) nums++;
		else break;
	}
	printf("%d %d\n",mi,nums);
	for(int i=1;i<=nums;i++) {
		printf("%d %d\n",a[i].id,a[i].score);
	}
	return 0;
} 
