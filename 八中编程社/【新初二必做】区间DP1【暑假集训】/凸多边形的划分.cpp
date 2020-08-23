#include <cstdio>
#include <algorithm>

const int MAXN = 55;
const __int128 INF = 1e55;

int n, a[MAXN] = {};
__int128 f[MAXN][MAXN];

void write(__int128 x) {
	if (x == 0) return;
    if(x < 0) {
        x = -x;
        putchar('-');
    }
	write(x / 10);
	putchar(x % 10 + '0');
	return;
}

void read(__int128 &x) {
	x = 0;
    int temp, flag = 1;
    while ((temp = getchar()) && (temp > '9' || temp < '0' || temp != '-'));
    if (temp == '-') flag = -flag;
    else x += temp - '0';
    while ((temp = getchar()) != '\n' && temp != ' ') x = temp - '0';
    x *= flag;
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int len = 3; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			f[i][j] = INF;
			for (int k = i + 1; k < j; k++) {
				__int128 temp = (__int128)a[i] * a[k] * a[j] + f[i][k] + f[k][j];
				f[i][j] = std::min(f[i][j], temp);
			}
		}
	}
	write(f[1][n]);
	return 0;
}
