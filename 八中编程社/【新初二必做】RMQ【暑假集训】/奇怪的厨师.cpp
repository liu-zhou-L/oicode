#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5e5 + 5;

long long sum[MAXN], ans = 0, n, m, l, r, a[MAXN];

template<typename T>
void read(T &x) {
	T k = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -1;
			ch = getchar();
			break;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	x = k * f;
	return;
}

struct NODE {
	int zhi, index;
} f[MAXN][25];

struct QUJIAN {
	int leftl, leftr, bestl, bestr, best;
	bool operator<(const QUJIAN &that) const {
		return (sum[this->bestr] - (this->best)) < (sum[that.bestr] - (that.best));
	}
};

priority_queue<QUJIAN> que;

int q(int s, int e) {
	int k = int(log2(double(e - s + 1)));
	return min(f[s][k].zhi, f[e - (1 << k) + 1][k].zhi);
}

int ql(int s, int e) {
	int k = int(log2(double(e - s + 1)));
	return f[s][k].zhi < f[e - (1 << k) + 1][k].zhi ? f[s][k].index : f[e - (1 << k) + 1][k].index;
}

int main() {
	//scanf("%d%d%d%d", &n, &m, &l, &r);
	read(n), read(m), read(l), read(r);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		sum[i] = sum[i - 1] + a[i];
		f[i][0].zhi = sum[i];
		f[i][0].index = i;
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) - 1 <= n; i++) {
			if (f[i][j - 1].zhi < f[i + (1 << j) - 1][j - 1].zhi) {
				f[i][j].zhi = f[i][j - 1].zhi;
				f[i][j].index = f[i][j - 1].index;
			}
			else {
				f[i][j].zhi = f[i + (1 << j) - 1][j - 1].zhi;
				f[i][j].index = f[i + (1 << j) - 1][j - 1].index;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int R = i - l, L = max(0, int(i - r));
		if (R < 0 || L > R) continue;
		QUJIAN temp;
		temp.leftl = L;
		temp.leftr = R;
		temp.bestr = i;
		temp.bestl = ql(temp.leftl, temp.leftr);
		temp.best = q(temp.leftl, temp.leftr);
		que.push(temp);
	}
	while (m-- && !que.empty()) {
		QUJIAN temp = que.top();
		que.pop();
		ans += sum[temp.bestr] - temp.best;
		QUJIAN temp_ = temp;
		temp_.leftr = temp.bestl - 1;
		if (temp_.leftl <= temp_.leftr) {
			temp_.best = q(temp_.leftl, temp_.leftr);
			temp_.bestl = ql(temp_.leftl, temp_.leftr);
			que.push(temp_);
		}
		temp_ = temp;
		temp_.leftl = temp.bestl + 1;
		if (temp_.leftl <= temp_.leftr) {
			temp_.best = q(temp_.leftl, temp_.leftr);
			temp_.bestl = ql(temp_.leftl, temp_.leftr);
			que.push(temp_);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
