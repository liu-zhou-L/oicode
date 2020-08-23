#include <cstdio>
#include <cstring>

const int MAXN = 1000005;

int n, a[MAXN], Bit[MAXN];
long long left[MAXN], right[MAXN], lup[MAXN], rup[MAXN], ans = 0, ans_ = 0;

int lowbit(int x) {
	return x & -x;
}

void update(int num, int x) {
	for (int i = num; i <= n; i += lowbit(i)) {
		Bit[i] += x;
	}
	return;
}

long long sum(int x) {
	long long ret = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		ret += Bit[i];
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		left[i] += sum(a[i] - 1);
		update(a[i], 1);
	}
	memset(Bit, 0, sizeof(Bit));
	for(int i = n; i > 0; i--){
		right[i] += sum(a[i] - 1);
		update(a[i], 1);
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += left[i] * right[i];
	}
	memset(Bit, 0, sizeof(Bit));
	for(int i = 1; i <= n; i++){
		lup[i] += sum(n) - sum(a[i]);
		update(a[i], 1);
	}
	memset(Bit, 0, sizeof(Bit));
	for(int i = n; i > 0; i--){
		rup[i] += sum(n) - sum(a[i]);
		update(a[i], 1);
	}
	for (int i = 1; i <= n; i++) {
		ans_ += lup[i] * rup[i];
	}
	printf("%lld %lld", ans_, ans);
	return 0;
} 
