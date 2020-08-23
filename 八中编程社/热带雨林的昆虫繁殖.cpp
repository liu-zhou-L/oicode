#include<cstdio>
long long a[55]={},b[55]={};
int main() {
	long long x,y,z;
	scanf("%lld%lld%lld",&x,&y,&z);
	for(int i=1;i<=x;i++) {
		a[i]=1;
		b[i]=0;
	}
	for(int i=x+1;i<=z+1;i++) {
		a[i]=a[i-1]+b[i-2];
		b[i]=b[i-x]+(a[i-x]-a[i-1-x])*y;
	}
	/*for(int i=1;i<=z+1;i++) {
		printf("%d ",a[i]);
	}*/
	printf("%lld",a[z+1]);
	return 0;
} 
