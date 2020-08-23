#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 45;
const int next[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct node {
	int x, y, sum;
};

int r, c;
char mg[MAXN][MAXN];
bool flag[MAXN][MAXN];
queue<node> f;

bool check(int x, int y) {
	return x >= 1 && x <= r && y >= 1 && y <= c && !flag[x][y];
}

int main() {
	node temp;
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		getchar();
		for (int j = 1; j <= c; j++) {
			mg[i][j] = getchar();
		}
	}
	temp.sum = 1;
	temp.x = 1;
	temp.y = 1;
	f.push(temp);
	while(1) {
		temp = f.front();
		if (temp.x == r && temp.y == c) {
			printf("%d", temp.sum);
			break;
		}
		for (int i = 0; i < 4; i++) {
			temp = f.front();
			temp.x += next[i][0];
			temp.y += next[i][1];
			temp.sum++;
			if(check(temp.x, temp.y)) {
				f.push(temp);
				flag[temp.x][temp.y] = 1;
			}
		}
		f.pop();
	}
	return 0;
}
