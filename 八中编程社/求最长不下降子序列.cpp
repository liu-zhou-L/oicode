#include <cstdio>

const int MAXN = 205;

int index = 1, a[MAXN], f[MAXN], prev[MAXN], n, ans = -1;

void print(int pre) {
	if(prev[pre] == pre) {
		printf("%d", a[pre]);
		return;
	}
	print(prev[pre]);
	printf(" %d", a[pre]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		f[i] = 1;
		prev[i] = i;
		for(int j = 1; j < i; j ++) {
			if(a[i] > a[j] && f[j] + 1 > f[i]) {
				f[i] = f[j] + 1;
				prev[i] = j;
			}
		}
		if(ans < f[i]) {
			ans = f[i];
			index = i;
		}
	}
	printf("max=%d\n", ans);
	print(index);
	return 0;
}
