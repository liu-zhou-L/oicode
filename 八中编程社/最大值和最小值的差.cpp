#include<cstdio>
int main() {
	int n,a[105],maxn=-999999999,maxindex,minn=999999999,minindex,b;
	scanf("%d",&n);
	for(int i=0;i<n;i+=1) {
		scanf("%d",&a[i]);
		if(a[i]>maxn) {
			maxn=a[i];
			maxindex=i;
		}
		if(a[i]<minn) {
			minn=a[i];
			minindex=i;
		}
	}
	b=a[maxindex];
	a[maxindex]=a[minindex];
	a[minindex]=b;
	for(int i=0;i<n;i+=1) printf("%d ",a[i]);
	return 0;
} 
