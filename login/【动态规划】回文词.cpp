#include<cstdio>
#include<cstring>
int maxn(int a,int b) { return a>b?a:b; }
int main() {
	int n,c[5005]={},d[5005]={};
	char a[5005],b[5005],t,maxx=-999999999;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%c",&t);
		a[i]=t;
		b[n-i+1]=t;
	}
	for(int i=1;i<=n;i+=1) {
		for(int j=1;j<=n;j++) {
			if(a[i]==b[j])
				d[j]=c[j-1]+1;
			else
				d[j]=maxn(c[j],d[j-1]);
			memcpy(c,d,n);
		}
	}
	for(int i=1;i<=n;i+=1) {
		if(c[i]>maxx) maxx=c[i];
	}
	printf("%d",n-maxx);
	return 0;
}
