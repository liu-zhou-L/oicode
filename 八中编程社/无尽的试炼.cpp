#include<cstdio>
#include<cmath>
bool f(int n) {
	for(int i=2;i*i<=n;i+=1) {
		if(n%i==0) return 0;
	}
	return 1;
}
int main() {
	int n;
	bool flag=1;
	scanf("%d",&n);
	printf("%d=",n);
	for(int i=n;i>=2;i-=1) {
		if(f(i)==1) {
			while(n%i==0) {
				if(flag==1) {
					printf("%d",i);
					flag=0;
				}
				else printf("*%d",i);
				n/=i;
			}
		}
	} 
	return 0;
}
