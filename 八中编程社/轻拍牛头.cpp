#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;

int oxen[MAXN], sum[MAXN] = {}, flag[MAXN] = {};

int main() {
	int n, mx = -999999999;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &oxen[i]);
		flag[oxen[i]] ++;
		mx = max(mx, oxen[i]);
	}
	for(int i = 1; i <= mx; i ++) {
		if(flag[i]) {
			for(int j = i; j <= mx; j += i) {
				sum[j] += flag[i];
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		printf("%d\n", sum[oxen[i]] - 1);
	}
	return 0;
}


