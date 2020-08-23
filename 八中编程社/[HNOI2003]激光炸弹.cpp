#include<cstdio>
int xi,yi,vi,a[5005][5005],n,r,sum=-999999999,now;
int main() {
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&xi,&yi,&vi);
		a[xi+1][yi+1]=vi;
	}
	for(int i=1;i<=5000;i++) {
		for(int j=1;j<=5000;j++) {
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
	for(int i=r;i<=5000;i++) {
		for(int j=r;j<=5000;j++) {
			now=a[i][j]-a[i-r][j]-a[i][j-r]+a[i-r][j-r];
			if(now>sum) sum=now;
		}
	}
	printf("%d",sum);
	return 0;
} 
