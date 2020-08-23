#include <cstdio>
//#include <cmath>

#define LL long long
#define LMAXN 0x3f3f3f3f3f3f3f3f

const int MAXN = 2 * 1e5 + 5;

struct ore {
	int w, v;
} ores[MAXN];

struct interval {
	int l, r;
} intervals[MAXN];

LL n, m, s, left = LMAXN, right = 0, sum, pre1[MAXN], pre2[MAXN];

LL mlabs(LL x) {
	return x >= 0 ? x : -x;
} 

bool check(LL x) {
	LL Y = 0;
	sum = 0;
	for(int i = 1; i <= n; i ++) {
		if(ores[i].w >= x) {
			pre1[i] = pre1[i - 1] + ores[i].v, pre2[i] = pre2[i - 1] + 1;
			//printf("pre1:%lld pre2:%lld ", pre1[i], pre2[i]);
		}
		else {
			pre1[i] = pre1[i - 1], pre2[i] = pre2[i - 1];
			//printf("pre1:%lld pre2:%lld ", pre1[i], pre2[i]);
		}
	}
	for(int i = 1; i <= m ; i ++) {
		Y += (pre1[intervals[i].r] - pre1[intervals[i].l - 1]) * (pre1[intervals[i].r] - pre1[intervals[i].l - 1]);
		//printf("temp2:%lld ", (pre1[intervals[i].r] - pre1[intervals[i].l - 1]) * (pre1[intervals[i].r] - pre1[intervals[i].l - 1]));
	}
	//printf("Y:%lld ", Y);
	sum = mlabs(Y - s);
	//printf("sum:%lld\n", sum);
	return Y > s;
}

int main() {
	scanf("%lld %lld %lld", &n, &m, &s);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &ores[i].w, &ores[i].v);
		if(ores[i].w > right) right = ores[i].w;
		if(ores[i].w < left) left = ores[i].w;
	}
	for(int i = 1; i <= m; i ++) {
		scanf("%d %d", &intervals[i].l, &intervals[i].r);
	} 
	left --;
	right ++;
	LL mid, ans = LMAXN;
	while(left + 1 < right) {
		mid = (left + right) / 2;
		if(check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
		if(sum < ans) ans = sum;
	}
	printf("%lld", ans);
	return 0;
}

