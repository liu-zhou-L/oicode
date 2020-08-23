#include <cstdio>
#include <algorithm>

const int MAXN = 105;

int t, n, a[MAXN], up[MAXN], down[MAXN], sum;

int main() {
	scanf("%d", &t);
	while(t --) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			up[i] = 1;
			down[i] = 1;
		}
		sum = 1;
		for(int i = 2; i <= n; i ++) {
			for(int j = 1; j < i; j ++) {
				if(a[i] < a[j] && up[j] + 1 > up[i]) {
					bool flag = 1;
					for(int k = i + 1; k < j; k ++) {
						if(a[k] > a[i] || a[k] > a[j]) {
							flag = 0;
							break;
						}
					}
					if(flag) {
						up[i] = up[j] + 1;
						sum = std::max(sum, up[i]);
					}
				}
			} 
		}
		for(int i = n - 1; i >= 1; i --) {
			for(int j = n; j > i; j --) {
				if(a[i] < a[j] && down[j] + 1 > up[i]) {
					bool flag = 1;
					for(int k = i + 1; k < j; k ++) {
						if(a[k] > a[i] || a[k] > a[j]) {
							flag = 0;
							break;
						}
					}
					if(flag) {
						down[i] = down[j] + 1;
						sum = std::max(sum, down[i]);
					}
				}
			} 
		}
		printf("%d\n", sum);
	}
	return 0;
}
