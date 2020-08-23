#include<cstdio>
int main() {
	int maxn=-999999999,minn=999999999,n,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) {
		scanf("%d",&a);
		if(maxn<a) maxn=a;
		if(minn>a) minn=a;
	}
	printf("%d %d",minn,maxn);
	return 0;
}
