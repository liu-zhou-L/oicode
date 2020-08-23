#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct node {
	long long data;
	bool operator<(const node &that) const {
		return this->data > that.data;
	}
	node() {}
	node(long long DATA) {
		data = DATA;
	}
}; 

int n;
long long ans = 0;
priority_queue<node> que;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		long long temp;
		scanf("%lld", &temp);
		que.push(node(temp));
	}
	for (int i = 1; i < n; i++) {
		long long tmp, tmp_;
		tmp = que.top().data, que.pop();
		tmp_ = que.top().data, que.pop();
		ans += tmp + tmp_;
		que.push(node(tmp + tmp_));
	}
	printf("%lld", ans);
	return 0;
}
