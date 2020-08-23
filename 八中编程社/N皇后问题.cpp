#include<cstdio>

bool a[20], b[20], c[45];//a竖，b左上到右下（差相同），c左右上到左下（和相同）
int sum = 0, n;

void search(int i) {
	for(int j = 1; j <= n; j ++) {
		if(a[j] == 0 && b[i - j + n -1] == 0 && c[i + j] == 0) {
			a[j] = 1;
			b[i - j + n -1] = 1;
			c[i + j] = 1;
			if(i == n) sum ++;
			else search(i + 1);
			a[j] = 0;
			b[i - j + n -1] = 0;
			c[i + j] = 0;
		}
	}
}
int main() {
	scanf("%d", &n);
	search(1);
	printf("%d", sum);
	return 0;
}

