#include<cstdio>
struct vl {
	int num[10005],len=1;
}a[10005],mid;
void long_mul2(vl &v1,vl &v2) {
	int x=0;
	v2.len=1;
	for(int i=1;i<=v1.len;i++) {
		x=0;
		v2.num[i]=v1.num[i]*2+x;
		x=v2.num[i]/10;
		v2.num[i]%=10;
	}
	v2.num[1+v1.len]=x;
	v2.len=v1.len+1;
	while(v2.num[v2.len]==0&&v2.len>1) v2.len--;
}
void long_add(vl &v1,vl &v2,vl &v3) {
	int x=0;
	v3.len=1;
	while(v3.len<=v1.len||v3.len<=v2.len) {
		v3.num[v3.len]=v1.num[v3.len]+v2.num[v3.len]+x;
		x=v3.num[v3.len]/10;
		v3.num[v3.len]%=10;
		v3.len++;
	}
	v3.num[v3.len]=x;
	while(v3.num[v3.len]==0&&v3.len>1) v3.len--;
}
int main() {
	int n;
	a[1].num[1]=1;
	a[1].len=1;
	a[2].num[1]=3;
	a[2].len=1;
	while(scanf("%d",&n)!=EOF) {
		for(int i=3;i<=n;i++) {
			mid.len=1;
			long_mul2(a[i-2],mid);
			long_add(a[i-1],mid,a[i]);
		}
		for(int i=a[i].len;i>=1;i--) {
			printf("%d",a[n].num[i]);
		}
		printf("\n");
	}
	//a[i]=a[i-1]+a[i-2]*2;
	return 0;
}
