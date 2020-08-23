#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 205;
const int nexts[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct node {
	int x, y, s, chakela;
} temp, temp2; 

queue<node> que;

int m, n, t, mrx, mry, zzx, zzy;
char maps[MAXN][MAXN];
bool book[MAXN][MAXN][20] = {};

int main() {
	scanf("%d %d %d", &m, &n, &t);
	for(int i = 1; i <= m; i ++) {
		getchar();
		for(int j = 1; j <= n; j ++) {
			scanf("%c", &maps[i][j]);
			if(maps[i][j] == '@') {
				mrx = i, mry = j;
			}
			if(maps[i][j] == '+') {
				zzx = i, zzy = j;
			}
		}
	}
	temp.x = mrx;
	temp.y = mry;
	temp.s = 0;
	temp.chakela = t;
	book[temp.x][temp.y][t] = 1;
	que.push(temp);
	while(!que.empty()) {
		temp = que.front();
		que.pop();
		for(int k = 0; k <= 3; k ++) {
			temp2.x = temp.x + nexts[k][0], temp2.y =  temp.y + nexts[k][1], temp2.s = temp.s + 1, temp2.chakela = temp.chakela;
			if(temp2.x >= 1 && temp2.x <= m && temp2.y >= 1 && temp2.y <= n) {
				if(temp2.x == zzx && temp2.y == zzy) {
					printf("%d", temp2.s);
					return 0;
				}
				if(maps[temp2.x][temp2.y] == '#') {
					if(temp2.chakela >= 1 && !book[temp2.x][temp2.y][temp2.chakela - 1]) {
						temp2.chakela -= 1;
						que.push(temp2);
						maps[temp2.x][temp2.y] = '@';
						book[temp2.x][temp2.y][temp2.chakela] = 1;
					}
				}
				else {
					if(!book[temp2.x][temp2.y][temp2.chakela]) {
						que.push(temp2);
						maps[temp2.x][temp2.y] = '@';
						book[temp2.x][temp2.y][temp2.chakela] = 1;	
					}
				}
			}
			/*printf("\n");
			for(int i = 1; i <= m; i ++) {
				for(int j = 1; j <= n; j ++) {
					printf("%c", maps[i][j]);
				}
				printf("\n");
			}*/
		}
	}
	printf("-1");
	/*for(int i = 1; i <= m; i ++) {
		for(int j = 1; j <= n; j ++) {
			printf("%c", maps[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
