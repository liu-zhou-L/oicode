#include<cstdio>
int a[110];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	a[n + 1] = 999999999;
	for(int i = 1; i <= n; i ++) {
		bool flag = 0;
		for(int j = 1; j <= n; j ++) {
			if(j <= i - 2 || j >= i + 2) {
				if(a[j] < a[j - 1] || a[j] > a[j + 1]) {
					flag = 1;
					break;
				}
			}
			else if(j == i - 1) {
				if(a[j] < a[j - 1] || a[j] > a[j + 2]) {
					flag = 1;
					break;
				}
			}
			else if(j == i + 1) {
				if(a[j] < a[j - 2] || a[j] > a[j + 1]) {
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0) {
			printf("True");
			return 0;
		}
	}
	printf("False");
	return 0;
}

