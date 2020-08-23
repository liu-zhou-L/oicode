#include <cstdio>

const int MAXN = 105;

int n, s, a[MAXN], f[MAXN];
bool flag = 0;

int dfs(int last = 0, int index = 1, int sh = s) {
	if(sh == 0) {
		for(int i = 1; i < index; i++) {
			printf("%d ", f[i]);
		}
		flag = 1;
		return 0;
	}
	for (int i = last + 1; i <= n; i++) {
		if(flag) {
			return 0;
		}	
		if(a[i] <= sh) {
			f[index] = a[i];
			dfs(i, index + 1, sh - a[i]);
		}
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dfs();
	if(!flag) {
		printf("No Answer!");
	}
	return 0;
} 
