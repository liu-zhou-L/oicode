#include<cstdio>
int main() {
	int ans=0,a,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		ans|=a;
	}
	printf("%d",ans);
	return 0;
}
/*
#include <cstdio>
int a[35];
int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        for (int j = 0; j < 32; ++j) a[j] += ((x >> j) & 1);
    }
    int ans = 0;
    for (int i = 0; i < 32; ++i)
        if (a[i] % 3 != 0)
            ans += (1 << i);
    printf("%d", ans);
    return 0;
}
*/
