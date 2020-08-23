#include<cstdio>
int main() {
	int n;
	long long sum=0,um=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) {
		um*=i;
		sum+=um;
	}	
	printf("%d",sum);
	return 0;
}
