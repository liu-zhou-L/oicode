#include<cstdio>
#include<cstring>
#include<cmath>
int main() {
	int ans=0,n,len,i=0;
	char a[10005];
	scanf("%d\n%s",&n,a);
	len = strlen(a);
	for(int i = 0; i < len; i ++) {
		ans += (a[len - i - 1] - '0') * pow(n, i);
	}
	printf("%d",ans);
	return 0;
}
