#include <cstdio>
#include <cstring>

const int MAXN = 1e5 + 5;

int n, a[MAXN], f[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	memset(f, 1, sizeof(f));
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if(a[i] & a[j]) {
				
			}
		}
	}
	return 0;
}
