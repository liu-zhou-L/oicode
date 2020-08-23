#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN = 1e5 + 5;

struct cx {
	int hao, kuan;
	bool operator<(cx that) {
		if (this -> kuan != that.kuan) {
			return this -> kuan < that.kuan;
		}
		else {
			return this -> hao < that.hao;
		}
	}
} l[MAXN];

int n, ans[2 * MAXN];
bool f;
stack<int> ren, bren;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &l[i].kuan);
		l[i].hao = i;
	}
	sort(l + 1, l + 1 + n);
	getchar();
	for (int i = 1; i <= 2 * n; i++) {
		f = getchar() - '0';
		if (f) {
			if (!ren.empty()) {
				ans[i] = l[ren.top()].hao;
				ans[ren.top()] = l[ren.top()].hao;
				ren.pop();
			}
			else {
				bren.push(i);
			}
		}
		else {
			if (!bren.empty()) {
				ans[i] = l[bren.top()].hao;
				ans[bren.top()] = l[bren.top()].hao;
				bren.pop();
			}
			else {
				ren.push(i);
			}
		}
	}
	for (int i = 1; i <= 2 * n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
} 
