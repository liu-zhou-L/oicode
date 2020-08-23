// Î´Íê³É 
#include <cstdio>

const int MAXN = 70;

int a[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1, j = 1, len = n; i <= len; i ++, j ++) {
		scanf("%d", &a[j]);
		if(a[j] > 50) {
			j --;
			n --;
		}
	}
	//for(int i = 1; i <= n; i ++) printf("%d ",a[i]);
	
	return 0;
}

