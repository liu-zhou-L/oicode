#include<cstdio>
int ans=0;
int main() {
	int a;
	scanf("%d",&a);
	while(a) {
		a&=(a-1);
		ans++;
	}
	printf("%d",ans);
	return 0;
}
