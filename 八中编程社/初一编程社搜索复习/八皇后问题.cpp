#include <cstdio>

const int MAXN = 20;

int sum = 0;
bool ans[MAXN][MAXN] = {}, flags[MAXN], flagh[MAXN], flagsx[MAXN], flagnx[MAXN]; 

bool check(int x, int y) {
	return !flags[x] && !flagh[y] && !flagsx[x - y + 8] && !flagnx[x + y];
}

void dfs(int hang = 1) {
	if(hang > 8) {
		sum += 1;
		printf("No. %d\n", sum);
		for (int i = 1; i <= 8; i++) {
			for(int j = 1; j <= 8; j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
		return;
	}
	for (int i = 1; i <= 8; i++) {
		if(check(hang, i)) {
			ans[hang][i] = 1;
			flags[hang] = 1;
			flagh[i] = 1;
			flagsx[hang - i + 8] = 1;
			flagnx[hang + i] = 1;
			dfs(hang + 1);
			ans[hang][i] = 0;
			flags[hang] = 0;
			flagh[i] = 0;
			flagsx[hang - i + 8] = 0;
			flagnx[hang + i] = 0;
		}
	}
}

int main() {
	dfs();
	return 0;
}
