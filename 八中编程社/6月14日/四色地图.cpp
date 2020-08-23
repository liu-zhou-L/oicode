#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXN = 30;

int n, ans[MAXN];
string scan;
bool a[MAXN][MAXN] = {}; 

bool dfs(int index = 1) {
	if (index > n) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", ans[i]);
		}
		return 1;
	}
	for (int i = 1; i <= 4; i++) {
		bool flag = 1;
		for (int j = 1; j <= n; j++) {
			if (a[index][j] && ans[j] == i && j != index) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			ans[index] = i;
			if (dfs(index + 1)) {
				return 1;
			}
			ans[index] = 0;	
		}
	}
}

int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		getline(cin, scan, '\n');
		int scan_len = scan.length();
		int t = 0;
		for (int j = 0; j < scan_len; j++) {
			if (scan[j] >= '0' && scan[j] <= '9') {
				t = t * 10 + scan[j] - '0';
			}
			else {
				a[i][t] = 1;
				t = 0;
			}
		}
	}
	dfs();
	return 0;
}
