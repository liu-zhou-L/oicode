#include<cstdio>
long long max(long long k,long long l) { return k>l?k:l; }
long long abs(long long k) { return k>0?k:-k; }
int main() {
	long long n,a[100005]={},k,z=0,f=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		k=a[i]-a[i-1];
		if(i>1) {
			if(k<0) f+=k;
			else z+=k;
		}
	}
	printf("%lld\n%lld",max(abs(f),z),abs(z+f)+1);
	return 0;
}
