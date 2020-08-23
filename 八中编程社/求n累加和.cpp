#include<cstdio>
#include<cstring>
int maxn(int a,int b) { return a>b?a:b;}
const int yw=10000;
int a[2055],c[2100][2100]={{1},{2}},lena=1,lenb=1,lenc=1,s3,n;
int main() {
	scanf("%d",&n);
	int m=n;
	for(lena=1,lenb=1;m;lena++,lenb++) {
		c[1][lena]=m%10;
		m/=10;
	}
	int x=0;
	for(int i=3;i<=n;i++) {
		lenc=1;
		x=0;
		while(lenc<=lenb) {
			c[i][lenc]=c[i-1][lenc]+c[1][lenc]+x;
			x=c[i][lenc]/10;
			c[i][lenc]%=10;
			lenc++;
		}
		c[i][lenc]=x;
		lenb=lenc;
	}
	while(c[n][lenc]==0&&lenc>1) lenc--;
	for(int i=lenc;i>=1;i--) printf("%d",c[n][i]);
	return 0;
}
