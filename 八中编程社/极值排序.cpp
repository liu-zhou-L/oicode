#include<cstdio>
#include <algorithm>
using namespace std;
int a[10005]={};
void f(int h,int t) {
	if(h>t) return;
	bool flag=1;
	int maxn=h,minn=h;
	for(int i=h;i<=t;i++) {
		if(a[minn]>a[i]) minn=i;
		if(a[maxn]<a[i]) maxn=i;
		if(a[i-1]>a[i]) flag=0;
	}
	if(flag==1) return;
	swap(a[minn],a[h]);
	swap(a[maxn],a[t]);
	f(h+1,t-1);
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f(1,n);
	/*for(int i=0;i<=n/2;i++) {
		//if(i>n-i) break;
		bool flag=1;
		int maxn=i+1,minn=n-i;
		for(int j=i+1;j<=n-i;j++) {
			if(a[minn]>a[j]) minn=j;
			if(a[maxn]<a[j]) maxn=j;
			if(a[j-1]>a[j]) flag=0;
		}
		if(flag==1) break;
		swap(a[minn],a[i]);
		swap(a[maxn],a[n-i]);
	} */
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}
