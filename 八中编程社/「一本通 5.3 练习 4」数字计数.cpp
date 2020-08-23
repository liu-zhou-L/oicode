#include<cstdio>
long long num[10];
int main() {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	for(int i=a;i<=b;i+=1) {
		int j=i,u;
		do {
			u=j%10;
			num[u]++;
			j/=10;
		}while(j>0);
	}
	for(int i=0;i<=9;i++) {
		printf("%lld ",num[i]);
	}
	return 0;
}
