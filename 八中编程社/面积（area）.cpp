#include <cstdio>
#include <queue>
using namespace std;

int map[15][15];
int next[4][2] = {{ 0, 1},
				  { 1, 0},
				  { 0,-1},
				  {-1, 0}};

queue<int> x;
queue<int> y;

void f(int h, int s) {
	if(h < 0 || h > 11 || s < 0 || s > 11 || map[h][s] == 1) return;
	map[h][s] = 1;
	x.push(h);
	y.push(h);
	for(int i = 0; i <= 3; i ++) {
		f(h + next[i][0], s + next[i][1]);
	}
}

int main() {
	for(int i = 1; i <= 10; i ++) {
		for(int j = 1; j <= 10; j ++) {
			scanf("%d", &map[i][j]);
		}
	}
	f(0, 0);
	//for(int i = 1; i <= 10; i ++) {
	//	for(int j = 1; j <= 10; j ++) {
	//		printf("%d ", map[i][j]);
	//	}
	//	printf("\n");
	//}
	int sum = 0;
	for(int i = 1; i <= 10; i ++) {
		for(int j = 1; j <= 10; j ++) {
			if(map[i][j] == 0) {
				sum ++;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
