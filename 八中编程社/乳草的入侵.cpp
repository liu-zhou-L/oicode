#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 105;
const int next[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

struct node {
	int x, y, num;
};

queue<node> rc;
int n, m, rn, rm, jl[MAXN][MAXN];
char map[MAXN][MAXN];
bool book[MAXN][MAXN] = {};

int main() {
	scanf("%d %d %d %d", &m, &n, &rn, &rm);
	for(int i = n; i >= 1; i --) {
		getchar();
		for(int j = 1; j <= m; j ++) {
			scanf("%c", &map[i][j]);
		}
	}
	node temp;
	temp.y = rn;
	temp.x = rm;
	temp.num = 0;
	map[rn][rm] = 'M';
	jl[rn][rm] = 0;
	book[rn][rm] = 1;
	rc.push(temp);
	while(!rc.empty()) {
		/*for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}*/
		for(int k = 0; k <= 7; k ++) {
			temp = rc.front();
			if(!book[temp.y + next[k][0]][temp.x + next[k][1]] && temp.y + next[k][0] <= n && temp.y + next[k][0] >= 1 && temp.x + next[k][1] <= m && temp.x + next[k][1] >= 1 && map[temp.y + next[k][0]][temp.x + next[k][1]] != '*') {
				temp.y += next[k][0];
				temp.x += next[k][1];
				temp.num ++;
				rc.push(temp);
				jl[temp.y][temp.x] = temp.num;
				book[temp.y][temp.x] = 1;
				map[temp.y][temp.x] = 'M';
			}
		}
		rc.pop();
		printf("\n");
	}
	int max = -999999999;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(jl[i][j] > max) {
				max = jl[i][j];
			}
		}
	}
	printf("%d", max);
	return 0;
}
