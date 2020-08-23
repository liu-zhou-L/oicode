#include<cstdio>
int sum=0;
bool f(int n) {
	for(int i=2;i*i<=n;i+=1)
		if(n%i==0) return 0;
		sum+=1;
	return 1;
}
int main() {
	int m,n;
	scanf("%d %d",&m,&n);
	for(;m<=n;m+=1) {
		if(f(m)) printf("%d ",m);
	}
	printf("\n%d",sum);
}
