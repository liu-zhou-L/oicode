#include<cstdio>
int main() {
	int n,a[1005],b[1005],sum=0,k,x,y,maxn=-999999999,maxindex,minn=999999999,minindex;
	scanf("%d",&n);
	int l=0;
	for(int i=0;i<n;i+=1) {
		scanf("%d",&a[i]);
		if(a[i]<=minn) {
			minn=a[i];
			minindex=i+1;
		}
		if(a[i]>10&&a[i]<100) {
			b[l]=a[i];
			l++;
		}
		sum+=a[i];
	}
	scanf("%d%d%d",&k,&x,&y);
	printf("%d\n",sum);
	for(int i=n-1;i>=0;i-=1) {
		printf("%d ",a[i]);
		if(a[i]>=maxn) {
			maxn=a[i];
			maxindex=i+1;
		}
	}
	printf("\n%d %d\n%d %d\n",maxn,maxindex,minn,minindex);
	printf("%d ",l);
	for(int i=0;i<l;i+=1) {
		printf("%d ",b[i]);
	}
	printf("\n");
	for(int i=n;i>=k;i-=1) {
		a[i]=a[i-1];
	}
	a[k-1]=x;
	for(int i=0;i<=n;i+=1) {
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i=0;i<=n;i+=1) {
		if(i+1!=y) printf("%d ",a[i]);
	}
	return 0;
}
