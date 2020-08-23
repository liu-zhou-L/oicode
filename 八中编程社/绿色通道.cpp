//×îºó±à¼­
#include <cstdio>

const int MAXN = 5 * 1e4 + 5; 

int a[MAXN], f[MAXN], n, t, left = 0, right = 0;

bool check(int x) {
	int minn = 999999999;
	for(int i = 1; i <= n; i ++) {
		if(i <= x + 1) {
			f[i] = a[i];
			if(f[i] < minn) {
				minn = f[i];
			}
		}
		else {
			f[i] = a[i] + minn;
		}
	}
	for(int i = n - x; i <= n; i ++) {
		if(f[i] <= t) return true;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &t);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	left = 0, right = n;
	int mid, ans = 0;
	printf("%d %d\n", left, right);
	while(left <= right) {
		mid = (left + right) >> 1;
		printf("mid:%d\n", mid);
		if(check(mid)) {
			right = mid - 1;
			ans = mid;
			printf("ans:%d\n", ans); 
		}
		else {
			left = mid + 1;
		}
		printf("%d %d\n", left, right);
	}
	printf("%d", ans);
	return 0;
}

