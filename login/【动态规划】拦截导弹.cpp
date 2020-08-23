#include<cstdio>
int uplen(int n,int a[5005]) {
	int maxx=-1,b[5005];
	for(int i=1;i<=n;i+=1) b[i]=1;
	for(int i=2;i<=n;i+=1) {
		for(int j=1;j<i;j+=1) {
			if(a[j]>=a[i]) {
				b[i]=b[j]+1>b[i]?b[j]+1:b[i];
			}
			if(b[i]>maxx) maxx=b[i];
		}
	}
	return maxx;
}
int nouplen(int n,int a[5005]) {
	int maxx=-1,b[5005];
	for(int i=1;i<=n;i+=1) b[i]=1;
	for(int i=2;i<=n;i+=1) {
		for(int j=1;j<i;j+=1) {
			if(a[j]<a[i]) {
				b[i]=b[j]+1>b[i]?b[j]+1:b[i];
			}
			if(b[i]>maxx) maxx=b[i];
		}
	}
	return maxx;
}
int main() {
	int a[5005]={},n=1;
	while(scanf("%d",&a[n])!=-1) n++;
	n--;
	printf("%d\n",uplen(n,a));
	printf("%d",nouplen(n,a));
	return 0;
}
