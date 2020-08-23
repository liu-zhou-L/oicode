#include<cstdio>

int map[30][30][30];

int w(int a, int b, int c) {
	if(a <= 0 or b <= 0 or c <= 0) {
		return 1;
	}
	if(a > 20 or b > 20 or c > 20) {
		if(map[20][20][20] == 0) return w(20, 20, 20);
		return map[20][20][20];
	}
	int ans = 0;
	if(a < b && b < c) {
		if(map[a][b][c - 1] == 0) {
			map[a][b][c - 1] = w(a, b, c - 1);
			ans += map[a][b][c - 1];
		}
		else ans += map[a][b][c - 1];
		if(map[a][b - 1][c - 1] == 0) {
			map[a][b - 1][c - 1] = w(a, b - 1, c - 1);
			ans += map[a][b - 1][c - 1];
		}
		else ans += map[a][b - 1][c - 1];
		if(map[a][b - 1][c] == 0) {
			map[a][b - 1][c] = w(a, b - 1, c);
			ans -= map[a][b - 1][c];
		}
		else ans -= map[a][b - 1][c];
		return ans;
	}
	else {
		if(map[a - 1][b][c] == 0) {
			map[a - 1][b][c] = w(a - 1, b, c);
			ans += map[a - 1][b][c];
		}
		else ans += map[a - 1][b][c];
		if(map[a - 1][b - 1][c] == 0) {
			map[a - 1][b - 1][c] = w(a - 1, b - 1, c);
			ans += map[a - 1][b - 1][c];
		}
		else ans += map[a - 1][b - 1][c];
		if(map[a - 1][b][c - 1] == 0) {
			map[a - 1][b][c - 1] = w(a - 1, b, c - 1);
			ans += map[a - 1][b][c - 1];
		}
		else ans += map[a - 1][b][c - 1];
		if(map[a - 1][b - 1][c - 1] == 0) {
			map[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
			ans -= map[a - 1][b - 1][c - 1];
		}
		else ans -= map[a - 1][b - 1][c - 1];
		return ans;
	}
}

int main() {
	int a, b, c;
	while(1) {
		scanf("%d %d %d", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1) break;
		printf("w(%d,%d,%d)=%d\n", a, b, c, w(a, b, c));
	}
	return 0;
}
