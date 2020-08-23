#include <cstdio>

const int MAXN = 5005;

long long n, a[MAXN], f[MAXN], vis[MAXN], ans = 0, sum = 0;

int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i ++) {
		for (int j = 1; j < i; j++){
			if(s[i] < s[j]){
				f[i] = std::max(f[i], f[j] + 1);
			}
		}
		ans = std::max(ans, f[i]);
		if(f[i] == 1) {
			vis[i] = 1;
		}
	}
	for(int i = 1; i <= n; i ++) {
		for (int j = 1; j < i; j++){
			if(s[i] < s[j]){
				f[i] = std::max(f[i], f[j] + 1);
			}
		}
		ans = std::max(ans, f[i]);
		if(f[i] == 1) {
			vis[i] = 1;
		}
	}
	printf("%lld", ans);
	printf("\n%lld", sum);
	return 0;
}
