#include<cstdio>
int main() {
	char a;
	int ans=0;
	while(scanf("%c",&a)!=EOF) {
		if(a>=48&&a<=57) ans++;
	}
	printf("%d",ans);
	return 0;
}
