#include<cstdio>

int cans[105], n, v;

bool f(int index,int s) {
	if(index > n) return 0;
	if(s == 0) return 1;
	for(int i = index + 1; i <= n; i ++) {
		if(f(i, s - cans[i]) == 1) return 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &v);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &cans[i]);
	}
	if(f(0, v) == 1) printf("yes");
	else printf("no");
	return 0;
}

