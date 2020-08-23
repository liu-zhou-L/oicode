#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > shu;
int n, m, q;

int main() {
	scanf("%d%d", &n, &m);
	shu.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &shu[i][j]);
		}
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", shu[x - 1][y - 1]);
	}
	return 0;
}
