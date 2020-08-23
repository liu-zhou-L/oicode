#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 35;

int n, q, a[MAXN], b[MAXN];

int quick_pow(int x, int y) {
	if(y == 0) {
		return 1;
	}
	else if(n % 2) {
		return quick_pow(x, y - 1) * x;
	}
	else {
		int temp = quick_pow(x, y / 2);
		return temp * temp;
	}
}

int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i ++) {
		int x, weshu = 0;
		scanf("%d", &x);
		while(x / 2) {
			weshu ++;
			x /= 2;
		}
		a[weshu] ++;
	}
	for(int i = 1; i <= q; i ++) {
		int chaxun, ans = 0;
		scanf("%d", &chaxun);
		for(int j = 0; j <= 35; j ++) {
			b[j] = a[j];
		}
		for(int j = 35; j >= 1; j --) {
			int k = min(a[j], chaxun / i);
			ans += k;
			chaxun -= k * i; 
		}
		if(chaxun) {
			printf("-1\n");
		}
		else {
			printf("%d\n", ans);
		}
	} 
	return 0;
}
