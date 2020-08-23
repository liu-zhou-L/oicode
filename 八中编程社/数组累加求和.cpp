#include<cstdio>
int main() {
	int n;
	scanf("%d",&n);
	int a,sum=0;
	for(int i=1;i<=n;i+=1) {
		scanf("%d",&a);
		sum+=a;
	}
	printf("%d",sum);
	return 0;
}
