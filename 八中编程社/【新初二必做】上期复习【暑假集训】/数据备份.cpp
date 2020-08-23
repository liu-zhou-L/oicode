#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

struct node {
	int index, v;
	bool operator<(const node &that) const {
		return this->v > that.v;
	}
	node() {}
	node(int INDEX, int V) {
		index = INDEX;
		v =V;
	}
};

int n, k, l[MAXN], r[MAXN], dp[MAXN]={};
bool flag[MAXN];
long long ans = 0;
priority_queue<node> que;

int main() {
	scanf("%d%d", &n, &k);
	int tmp, tmp_;
	scanf("%d", &tmp);
	for (int i = 1; i < n; i++) {
		scanf("%d", &tmp_);
		dp[i] = tmp_ - tmp;
		que.push(node(i, dp[i]));
		l[i] = i - 1;
		r[i] = (i + 1 == n) ? 0 : (i + 1);
		tmp = tmp_;
	}
	dp[0] = INF;
	while (k) {
		node now = que.top();
		que.pop();
		if (flag[now.index]) continue;
		int i = now.index;
		flag[l[i]] = 1;
		flag[r[i]] = 1;
		ans += dp[i];
		dp[i] = dp[l[i]] + dp[r[i]] - dp[i];
		que.push(node(i, dp[i]));
		l[i] = l[l[i]];		
		r[i] = r[r[i]];		 
		r[l[i]] = i;
		l[r[i]] = i;			 
		k--;
	}
	printf("%lld", ans);
	return 0;
}
