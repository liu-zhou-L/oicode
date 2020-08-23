#include<cstdio>
int main() {
	int a;
	scanf("%d",&a);
	if(a%10==a/100) printf("YES");
	else printf("NO");
	return 0;
}
