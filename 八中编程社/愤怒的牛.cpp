#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;

int a[MAXN], n, m, left = 0, right = 0;

bool check(int x) {
	int tot = 0, sum = 1;
	for(int i = 1; i <= n; i ++) {
		if(tot + a[i] - a[i - 1] < x) {
			tot += a[i] - a[i - 1];
		}
		else {
			tot = 0;
			sum ++;
		}
	}
	return sum >= m;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		if(a[i] > right) right = a[i];
	}
	sort(a + 1, a + 1 + n);
	a[0] = a[1];
	int mid;
	while(left + 1 < right) {
		mid = (left + right) / 2;
		if(check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	printf("%d", left);
	return 0;
}

