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
		for (int i = 1; i <= 8; i++) {
			for(int j = 1; j <= 8; j++) {
				if(ans[i][j]) {
					printf("%d ", j);
				}
			}
		}
		printf("\n");
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
	printf("%d", sum);
	return 0;
}

//#include <cstdio>
//
//int main() {
//	printf("1 5 8 6 3 7 2 4\n1 6 8 3 7 4 2 5\n1 7 4 6 8 2 5 3\n1 7 5 8 2 4 6 3\n2 4 6 8 3 1 7 5\n2 5 7 1 3 8 6 4\n2 5 7 4 1 8 6 3\n2 6 1 7 4 8 3 5\n2 6 8 3 1 4 7 5\n2 7 3 6 8 5 1 4\n2 7 5 8 1 4 6 3\n2 8 6 1 3 5 7 4\n3 1 7 5 8 2 4 6\n3 5 2 8 1 7 4 6\n3 5 2 8 6 4 7 1\n3 5 7 1 4 2 8 6\n3 5 8 4 1 7 2 6\n3 6 2 5 8 1 7 4\n3 6 2 7 1 4 8 5\n3 6 2 7 5 1 8 4\n3 6 4 1 8 5 7 2\n3 6 4 2 8 5 7 1\n3 6 8 1 4 7 5 2\n3 6 8 1 5 7 2 4\n3 6 8 2 4 1 7 5\n3 7 2 8 5 1 4 6\n3 7 2 8 6 4 1 5\n3 8 4 7 1 6 2 5\n4 1 5 8 2 7 3 6\n4 1 5 8 6 3 7 2\n4 2 5 8 6 1 3 7\n4 2 7 3 6 8 1 5\n4 2 7 3 6 8 5 1\n4 2 7 5 1 8 6 3\n4 2 8 5 7 1 3 6\n4 2 8 6 1 3 5 7\n4 6 1 5 2 8 3 7\n4 6 8 2 7 1 3 5\n4 6 8 3 1 7 5 2\n4 7 1 8 5 2 6 3\n4 7 3 8 2 5 1 6\n4 7 5 2 6 1 3 8\n4 7 5 3 1 6 8 2\n4 8 1 3 6 2 7 5\n4 8 1 5 7 2 6 3\n4 8 5 3 1 7 2 6\n5 1 4 6 8 2 7 3\n5 1 8 4 2 7 3 6\n5 1 8 6 3 7 2 4\n5 2 4 6 8 3 1 7\n5 2 4 7 3 8 6 1\n5 2 6 1 7 4 8 3\n5 2 8 1 4 7 3 6\n5 3 1 6 8 2 4 7\n5 3 1 7 2 8 6 4\n5 3 8 4 7 1 6 2\n5 7 1 3 8 6 4 2\n5 7 1 4 2 8 6 3\n5 7 2 4 8 1 3 6\n5 7 2 6 3 1 4 8\n5 7 2 6 3 1 8 4\n5 7 4 1 3 8 6 2\n5 8 4 1 3 6 2 7\n5 8 4 1 7 2 6 3\n6 1 5 2 8 3 7 4\n6 2 7 1 3 5 8 4\n6 2 7 1 4 8 5 3\n6 3 1 7 5 8 2 4\n6 3 1 8 4 2 7 5\n6 3 1 8 5 2 4 7\n6 3 5 7 1 4 2 8\n6 3 5 8 1 4 2 7\n6 3 7 2 4 8 1 5\n6 3 7 2 8 5 1 4\n6 3 7 4 1 8 2 5\n6 4 1 5 8 2 7 3\n6 4 2 8 5 7 1 3\n6 4 7 1 3 5 2 8\n6 4 7 1 8 2 5 3\n6 8 2 4 1 7 5 3\n7 1 3 8 6 4 2 5\n7 2 4 1 8 5 3 6\n7 2 6 3 1 4 8 5\n7 3 1 6 8 5 2 4\n7 3 8 2 5 1 6 4\n7 4 2 5 8 1 3 6\n7 4 2 8 6 1 3 5\n7 5 3 1 6 8 2 4\n8 2 4 1 7 5 3 6\n8 2 5 3 1 7 4 6\n8 3 1 6 2 5 7 4\n8 4 1 3 6 2 7 5\n92");
//	return 0;
//}
