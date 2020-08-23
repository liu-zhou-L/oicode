#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 50;

struct Node {
	int xmin, xmax, ymin, ymax;
} ppt[MAXN];

struct node {
	int x, y;
} num[MAXN];

int n, sum = 0, in[MAXN], ans[MAXN];
bool book[MAXN][MAXN] = {};

bool check(Node x, node y) {
	return x.xmin <= y.x && x.xmax >= y.x && x.ymin <= y.y && x.ymax >= y.y;
}

void topo(int x) {
	sum++;
	in[x]--;
	for (int i = 1; i <= n; i++) {
		if (book[x][i]) {
			ans[i] = x;
			book[x][i] = false;
			for (int j = 1; j <= n; j++) {
				if (book[j][i]) {
					in[j]--;
					book[j][i] = false;
					if (in[j] == 1) topo(j);
				}
			}
			break;
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &ppt[i].xmin, &ppt[i].xmax, &ppt[i].ymin, &ppt[i].ymax);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &num[i].x, &num[i].y);
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (check(ppt[j], num[i])) {
				book[i][j] = true;
				temp++;
			}
		}
		in[i] = temp;
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 1) {
			topo(i);
		}
	}
	if (sum < n) {
		printf("None");
	}
	else {
		for (int i = 1; i <= n; i++) {
			printf("%c %d\n",i + 64 , ans[i]);
		}
	}
	return 0;
}
