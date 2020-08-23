#include <cstdio>

const int MAXN = 1e6 + 5;

int n, a[30], b[MAXN], Bit[MAXN];
long long ans = 0;
char s[MAXN], s_[MAXN];

int lowbit(int x) {
	return x & -x;
}

void update(int x) {
	for (int i = x; i <= n; i += lowbit(i)) {
		Bit[i]++;
	}
	return;
}

long long sum(int x) {
	long long ret = 0;
	for(int i = x; i > 0; i -= lowbit(i)) {
		ret += Bit[i];
	}
	return ret;
}

int main() {
	scanf("%d%s%s", &n, s + 1, s_ + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = a[s[i] - 'A'];
		a[s[i] - 'A'] = i;
	}
	for (int i = n; i >= 1; i--) {
		int temp = a[s_[i] - 'A'];
		a[s_[i] - 'A'] = b[temp];
		ans += sum(temp);
		update(temp);
	}
	printf("%lld", ans);
	return 0;
}
