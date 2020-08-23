#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 400005;

struct node {
	int value, num;
	bool operator<(const node &that) const {
		return value > that.value;
	}
};

priority_queue<node> que;

int n, a[MAXN], b[MAXN], c[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		c[i] = 2;
		node tmp;
		tmp.value = a[i] + b[1];
		tmp.num = i;
		que.push(tmp);
	}
	for (int i = 1; i <= n; i++) {
		node tmp = que.top();
		que.pop();
		printf("%d\n", tmp.value);
		tmp.value = a[tmp.num] + b[c[tmp.num]++];
		que.push(tmp);
	}
	return 0;
}
