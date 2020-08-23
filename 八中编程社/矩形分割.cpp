//×îºó±à¼­2020/2/29
#include <cstdio>

#define LL long long

const int MAXN = 1e4 + 5;
const int lMAXN = 1e6 + 5;

LL r, n, left = 0, right = 0, a[lMAXN];

struct rectangle {
	LL l, t, w, h;
} rectangles[MAXN];

int check(LL x) {
	LL sum = 0;
	for(int i = 0; i <= r; i ++) {
		if(i < x) sum += a[i];
		else sum-= a[i];
	}
	return sum > 0;
}

int main() {
	scanf("%lld %lld", &r, &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld %lld %lld %lld", &rectangles[i].l, &rectangles[i].t, &rectangles[i].w, &rectangles[i].h);
		for(int j = rectangles[i].l; j < rectangles[i].l + rectangles[i].w; i ++) {
			a[j] += rectangles[i].h;
		}
	}
	right = r, left = 0;
	LL mid;
	printf("%lld %lld\n", left, right);
	while(left + 3 < right) {
		mid = (left + right) / 2;
		if(check(mid)) {
			right = mid;
		}
		else {
			left = mid;
		}
		printf("%lld %lld\n", left, right);
		if(check(mid) == 0) {
			break;
		}
	}
	/*long long minn = 999999999999, ans;
	for(int i = right; i >= left; i --) {
		long long s = check(i);
		if(s >= 0 && s < minn) {
			minn = s;
			ans = i;
		}
	}
	while(a[ans] == 0 && ans < r) {
		ans ++;
	}*/
	printf("%lld", right);
	return 0;
}

