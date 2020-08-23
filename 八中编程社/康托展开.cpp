//最后编辑
#include <cstdio>
#include <cmath>

const int MAXN = 1e5 + 5;

int n, a[MAXN], sum = 0, now[MAXN];
bool flag[MAXN];

/*
//深搜 
void f(int x) {
	if(x > n) {
		sum ++;
		for(int i = 1; i <= n; i ++) {
			if(now[i] != a[i]) {
				return;
			}
		}
		printf("%d\n", sum);
		return;
	}
	for(int i = 1; i <= n; i ++) {
		if(flag[i] == 0) {
			flag[i] = 1;
			now[x] = i;
			f(x + 1);
			flag[i] = 0;
		}
	}
}
*/

int jc(int x) {
	int ans = 1;
	for(int i = 2; i <= x; i ++) {
		ans *= i;
	}
	return ans;
} 

//真-康托展开
int f() {
	int ans = 0, sum = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if()
		}
		ans += jc(n - i) * a[i];
	}
	return ans;
} 

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	printf("%d", f());
	return 0;
}

