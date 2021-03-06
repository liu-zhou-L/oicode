#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 1e4 + 5;

int t, n, k, s[MAXN];
bool  f[MAXN][105];////f[i][j]表示前i个数字运算之后余数是否为j

int main() {
	scanf("%d", &t);
	while(t --) {
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &s[i]);
			s[i] = int(fabs(s[i])) % k;//s[i]为第i个元素模k的值 
		}
		memset(f, 0, sizeof(f));//清除前一次的记录 
		f[1][s[1]] = 1;//初始化 
		for(int i = 2; i <= n; i ++) {
			for(int j = k - 1; j >= 0; j --) {
				if(f[i - 1][j]) {//如果前i - 1个元素模k等于j 
					f[i][(j + s[i]) % k] = 1;//那么前i-1个值的和加上第i个元素模k等于加上第i个元素后模k的值
					f[i][((j - s[i]) % k + k) % k] = 1;//前i-1个值的和减去第i个元素模k的值为j减去第i个元素后模k再加k的值
				}
			}
		}
		if(f[n][0]) {//检查所有元素的和能否被k整除 
			printf("Divisible\n");
		}
		else {
			printf("Not divisible\n");
		}
	}
	return 0;
}
