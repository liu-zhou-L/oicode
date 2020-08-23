//×îºó±à¼­
#include <cstdio>
#include <cmath>

const int MAXN = 30;

int n, result[MAXN];
char add1[MAXN], add2[MAXN], sumn[MAXN];
bool flag = 1;

void dfs(int x) {
	if(x > n) {
		int sum = 0;
		for(int i = n; i >= 1; i ++) {
			sum += (result[add1[i] - 64]) * pow(n - i, n) + (result[add2[i] - 64]) * pow(n - i, n);
		}
		for(int i = n; i >= 1; i ++) {
			if(sum % 10 != result[sumn[i] - 64]) {
				flag = 0;
				break;
			}
			sum /= 10;
		}
		if(flag == 1) {
			for(int i = 1; i <= n; i ++) {
				printf("%c ", result[i]);
			}
		}
		return;
	}
	for(int i = 0; i <= 9; i ++) {
		result[x] = i;
		dfs(x + 1);
		if(flag == 1) return;
	}
}

int main() {
	scanf("%d\n", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%c", &add1[i]);
	}
	scanf("\n");
	for(int i = 1; i <= n; i ++) {
		scanf("%c", &add2[i]);
	}
	scanf("\n");
	for(int i = 1; i <= n; i ++) {
		scanf("%c", &sumn[i]);
	}
	dfs(1);
	return 0;
}

