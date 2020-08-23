//最后编辑20/3/6
#include <cstdio>

const int MAXN = 15;
int next[][2] ={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct node {
	int x, y, fx;
} c, m;

char map[MAXN][MAXN];

int main() {
	int n;
	scanf("%d\n", &n);
	while(n --) {
		for(int i = 1; i <= 10; i ++) {
			for(int j = 1; j <= 10; j ++) {
				scanf("%c", &map[i][j]);
				if(map[i][j] == 'C') {
					c.x = i, c.y = j;
				}
				else if(map[i][j] == 'M') {
					m.x = i, m.y = j;
				}
			}
			getchar();
		}
		int sum = 0;
		bool flag = 0;
		while((c.x != m.x) && (c.y != m.y)) {
			sum ++;
			if(sum > 100) {
				printf("-1\n");
				flag = 1;
				break;
			}
			if((c.x + next[c.fx][0] <= n && c.x + next[c.fx][0] >= 1) && (c.y + next[c.fx][1] <= n && c.y + next[c.fx][1] >= 1) && map[c.x + next[c.fx][0]][c.y + next[c.fx][1]] != '*') {
				map[c.x][c.y] = '.';
				c.x += next[c.fx][0], c.y += next[c.fx][1];
				map[c.x][c.y] = 'C';
				printf("C执行移动\n");
			}
			else {
				if(c.fx != 3) c.fx ++;
				else c.fx = 0;
				printf("C执行变向\n");
			}
			if((m.x + next[m.fx][0] <= n && m.x + next[m.fx][0] >= 1) && (m.y + next[m.fx][1] <= n && m.y + next[m.fx][1] >= 1) && map[m.x + next[m.fx][0]][m.y + next[m.fx][1]] != '*') {
				map[m.x][m.y] = '.';
				m.x += next[m.fx][0], m.y += next[m.fx][1];
				map[m.x][m.y] = 'M';
				printf("M执行移动\n");
			}
			else {
				if(m.fx != 3) m.fx ++;
				else m.fx = 0;
				printf("M执行变向\n");
			}
			printf("%d:\n", sum);
			for(int i = 1; i <= 10; i ++) {
				for(int j = 1; j <= 10; j ++) {
					printf("%c", map[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		if(flag == 0) {
			printf("%d\n", sum);
		}
	}
	return 0;
}

