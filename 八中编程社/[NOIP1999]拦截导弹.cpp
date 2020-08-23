#include <cstdio>
#include <algorithm>

const int MAXN = 30005;

int a[MAXN], up[MAXN], down[MAXN], len = 1, uplen = 0, downlen = 0;

int main() {
	len = 1;
	while(scanf("%d", &a[len]) != -1) {
		len ++;
	}
	for(int i = 1; i < len; i ++) {
		up[i] = 1;
		for(int j = 1; j < i; j ++) {
			if(a[i] <= a[j]) {
				up[i] = std::max(up[i], up[j] + 1);
			}
		}
		uplen = std::max(uplen, up[i]);
	}
	for(int i = 1; i < len; i ++) {
		down[i] = 1;
		for(int j = 1; j < i; j ++) {
			if(a[i] > a[j]) {
				down[i] = std::max(down[i], down[j] + 1);
			}
		}
		downlen = std::max(downlen, down[i]);
	}
	printf("%d\n%d", uplen, downlen);
	return 0;
}
