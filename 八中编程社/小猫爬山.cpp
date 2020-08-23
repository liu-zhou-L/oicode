#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 20;

int n, w, cats[MAXN], f[MAXN], ans;
bool book[MAXN];

void dfs(int ind = 1 /*��ǰè�����*/, int sum = 0 /*��ǰ�����³���*/) {
	if(sum > ans) return; //������ǰ����³�������ֱ���˳� 
	if(ind == n + 1) { //����èȫ�����ϳ������³����������ڵ�ǰ����³����������沢�˳� 
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
