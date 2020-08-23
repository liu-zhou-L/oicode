#include<cstdio>
#include<algorithm>
using namespace std;
struct stu{
	int stun,score,c,m,e;
}a[305];
bool cmp(stu s1,stu s2) {
	if(s1.score!=s2.score)
		return s1.score>s2.score;
	else if(s1.c!=s2.c)
		return s1.c>s2.c;
	else
		return s1.stun<s2.stun;
}
int n;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i].c,&a[i].m,&a[i].e);
		a[i].stun=i;
		a[i].score=a[i].c+a[i].m+a[i].e;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=5;i++) {
		printf("%d %d\n",a[i].stun,a[i].score);
	}
	return 0;
}

