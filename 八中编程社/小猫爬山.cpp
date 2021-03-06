#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 20;

int n, w, cats[MAXN], f[MAXN], ans;
bool book[MAXN];

void dfs(int ind = 1 /*当前猫的序号*/, int sum = 0 /*当前已用缆车数*/) {
	if(sum > ans) return; //超过当前最大缆车数量，直接退出 
	if(ind == n + 1) { //所有猫全部坐上车，且缆车数量不大于当前最大缆车数量，保存并退出 
		if(sum < ans) ans = sum;
		return; 
	}
	for(int i = 1; i <= sum; i ++) {
		if(cats[ind] + f[i] <= w) {
			f[i] += cats[ind];
			dfs(ind + 1, sum);
			f[i] -= cats[ind];
		}
	}
	f[sum + 1] = cats[ind];
	dfs(ind + 1, sum + 1);
	f[sum + 1] = 0;
}

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	scanf("%d %d ", &n, &w);
	for(int i = 1; i <= n ; i ++) {
		scanf("%d", &cats[i]);
	}
	ans = n;
	sort(cats + 1, cats + 1 + n, cmp);
	dfs();
	printf("%d", ans);
	return 0;
}
