#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2 * 1e5 + 5;

struct data {
	int s, e;
	bool operator<(const data &that) const {
		if (this->s == that.s) return this->e > that.e;
		else return this->s < that.s;
	}
} edge[MAXN];

struct node {
	int l, r;
	bool operator<(const node &that) const  {
		if (this->r != that.r) return this->r < that.r;
		return this->l < that.l;
	}
	node() {}
	node(const int L, const int R) {
		this->l = L;
		this->r = R;
	}
};

int t, n, m, k, a, s[MAXN], left, right, Bit[MAXN];

int lowbit(int x) {
	return x & -x;
}

void update(int num, int x) {
	for (int i = num; i <= n; i += lowbit(i)) {
		Bit[i] += x;
	}
	return;
}

int Sum(int num) {
	int ret = 0;
	for (int i = num; i > 0; i -= lowbit(i)) {
		ret += Bit[i];
	}
	return ret;
}

bool check(int x) {
	memset(Bit, 0, sizeof(Bit));
	for (int i = 1; i <= n; i++) update(i, s[i] - s[i - 1]);
	priority_queue<node> que;
	int now = 1, tot = 0;
	for (int i = 1; i <= n; i++) {
		while (edge[now].s <= i && now <= m) {
			que.push(node(edge[now].s, edge[now].e));
			now++;
		}
		while (Sum(i) < x) {
			if (que.empty() || tot == k) return false;
			node tmp = que.top();
			que.pop();
			update(tmp.l, a);
			update(tmp.r + 1, -a);
			tot++;
		}
	}
	return true;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		left = 0;
		right = 0x3f3f3f3f;
		scanf("%d%d%d%d", &n, &m, &k, &a);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &s[i]);
			right = min(right, s[i]);
		}
		right += k * a + 1;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &edge[i].s, &edge[i].e);
		}
		sort(edge + 1, edge + 1 + n);
		while (right - left > 1) {
			//printf("l:%d r:%d\n", left, right);
			int mid = (right + left) >> 1;
			if (check(mid)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		//printf("l:%d r:%d\n", left, right);
		printf("%d\n", left);
	}
	return 0;
}
