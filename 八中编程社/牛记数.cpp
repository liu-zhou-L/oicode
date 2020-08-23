#include <cstdio>

int s, t, ans = 0;

bool check(int x) {
	int tot = 0;
	while(x) {
		tot += x & 1;
		if(tot > 4) return false;
		x >>= 1;
	}
	//return tot;
	return true;
}

int main() {
	scanf("%d %d", &s, &t);
	for(int i = s; i <= t; i ++) {
		if(check(i)) {
			//printf("%d ", check(i));
			//printf("%d\n", i);
			ans ++;
		}
	}
	printf("%d", ans);
	return 0;
}
