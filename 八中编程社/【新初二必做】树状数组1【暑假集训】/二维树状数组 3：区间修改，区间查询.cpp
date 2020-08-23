#include <cstdio>
#include <cstring>

const int MAXN = 2050;

int n, m;
long long a_1[MAXN][MAXN], a_2[MAXN][MAXN], a_3[MAXN][MAXN], a_4[MAXN][MAXN];

int lowbit(int x) {
	return x & -x;
}

void update(int x, int y, long long z) {
	for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= n; j += lowbit(j)) {
            a_1[i][j] += z;
            a_2[i][j] += x * z;
            a_3[i][j] += y * z;
            a_4[i][j] += x * y * z;
        }
    }
    return;
}

long long sum(int x, int y) {
	long long ret = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            ret += (x + 1) * (y + 1) * a_1[i][j] - (y + 1) * a_2[i][j] - (x + 1) * a_3[i][j] + a_4[i][j];
        }
    }
    return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(a_1, 0, sizeof(a_1));
    memset(a_2, 0, sizeof(a_2));
    memset(a_3, 0, sizeof(a_3));
    memset(a_4, 0, sizeof(a_4));
    int temp, a, b, c, d;
    long long x;
    while (~scanf("%d%d%d%d%d", &temp, &a, &b, &c, &d)) {
    	switch(temp) {
    		case 1: {
    			scanf("%lld", &x);
    			update(a, b, x);
    			update(c + 1, b, -x);
    			update(a, d + 1, -x);
    			update(c + 1, d + 1, x);
				break;
			}
			case 2: {
				printf("%lld\n", sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1));
				break;
			}
		}
	}
	return 0;
}
