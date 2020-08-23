#include <cstdio>

struct que{
	int a[100005], head, last, len;
	que(int s = 0) {
		head = 0, last = s, len = s;
		for(int i = 1; i <= s; i ++) {
			a[head + i - 1] = i;
		}
	}
	int add(int addn) {
		a[last] = addn;
		last ++;
		len ++;
		return addn;
	}
	int reduce(){
		len --;
		head ++;
		return a[head - 1];
	}
};

int main() {
	int m, n, k;
	scanf("%d %d %d", &m , &n, &k);
	que ms(m), ns(n);
	int mn, mm;
	for(int i = 1; i <= k; i ++) {
		printf("%d %d\n", mm = ms.reduce(), mn = ns.reduce());
		ms.add(mm), ns.add(mn);
	}
	return 0;
}

