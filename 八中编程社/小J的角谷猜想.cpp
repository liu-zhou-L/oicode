#include<cstdio>
int main() {
	long long n,k,i=0;
	scanf("%lld%lld",&n,&k);
	while(n>1) {
		i++;
		if(i>k) {
			printf("too long");
			break;
		} 
		if(n%2==0) {
			printf("%lld/2=%lld\n",n,n/2);
			n/=2;
		}
		else {
			printf("%lld*3+1=%lld\n",n,n*3+1);
			n=n*3+1;
		}
	}
	return 0;
}
