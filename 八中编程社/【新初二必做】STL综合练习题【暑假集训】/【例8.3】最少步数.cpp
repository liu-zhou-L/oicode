#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int NEXT[][2] = {{-2, 1}, {-2, 2}, {-1, 2}, {1, 2}, {2, 2}, {2, 1}, {2, -1}, {2, -2}, {1, -2}, {-1, -2}, {-2, -2}, {-2, -1}};

struct node {
	int x, y, tot;
	node () { tot = 0; }
} ma1, ma2, temp;

int minn1, minn2;
bool flag[105][105];
queue<node> que;

bool check(node x) {
	return x.x >= 1 && x.x <= 100 && x.y >= 1 && x.y <= 100 && !flag[x.x][x.y];
}

int main() {
	scanf("%d%d%d%d", &ma1.x, &ma1.y, &ma2.x, &ma2.y);
	que.push(ma1);
	memset(flag, 0, sizeof(flag));
	flag[ma1.x][ma1.y] = 1;
	while (!que.empty()) {
		temp = que.front();
		if (temp.x == 1 && temp.y == 1) {
			printf("%d\n", temp.tot);
			break;
		}
		for (int i = 0; i <= 11; i++) {
			temp = que.front();
			temp.x += NEXT[i][0];
			temp.y += NEXT[i][1];
			temp.tot++;
			if (check(temp)) {
				flag[temp.x][temp.y] = 1;
				que.push(temp);
			}
		}
		que.pop();
	}
	while (!que.empty()) que.pop();
	que.push(ma2);
	memset(flag, 0, sizeof(flag));
	flag[ma2.x][ma2.y] = 1;
	while (!que.empty()) {
		temp = que.front();
		if (temp.x == 1 && temp.y == 1) {
			printf("%d", temp.tot);
			break;
		}
		for (int i = 0; i <= 11; i++) {
			temp = que.front();
			temp.x += NEXT[i][0];
			temp.y += NEXT[i][1];
			temp.tot++;
			if (check(temp)) {
				flag[temp.x][temp.y] = 1;
				que.push(temp);
			}
		}
		que.pop();
	}
	return 0;
}
