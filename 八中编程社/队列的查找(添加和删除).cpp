#include<cstdio>
int main() {
	int n,a[10005],x,xindex;
	bool xflag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) scanf("%d",&a[i]);
	scanf("%d",&x);
	for(int i=1;i<=n;i+=1) {
		if(a[i]==x) {
			xflag=1;
			break;
		}
		if(a[i]>x) {
			xindex=i;
			break;
		}
	}
	if(xflag==1) {
		for(int i=1;i<=n;i+=1)
			if(a[i]!=x) printf("%d ",a[i]);
	}
	else {
		for(int i=1;i<=n;i+=1) {
			if(i==xindex) printf("%d ",x);
			printf("%d ",a[i]);
		}
		if(x>a[n]) printf("%d",x);
	}
	return 0;
}
