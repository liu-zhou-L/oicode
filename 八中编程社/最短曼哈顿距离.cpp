#include<cstdio>
#include<cmath>
struct code{
	int x,y;
}a[100005];
int main() {
	int ans=999999999,ansindex=0,n,now=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=n-1;i>=2;i--) {
		now=0;
		for(int j=1;j<n;j++) {
			if(j==i-1) {
				now+=fabs(a[j+2].x-a[j].x)+fabs(a[j+2].y-a[j].y);
				j++;
			}
			else now+=fabs(a[j+1].x-a[j].x)+fabs(a[j+1].y-a[j].y);
		}
		if(now<ans) {
			ans=now;
			ansindex=i;
		}
	}
	printf("%d %d",ansindex,ans);
	return 0;
}

