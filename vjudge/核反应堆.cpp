#include<cstdio>

const int MAXN = 40;

long long gaoneng[MAXN] = {}, dineng[MAXN] = {};

int main() {
	gaoneng[0] = 1;
	dineng[0] = 0;
	for(int i = 1; i <= 33; i ++) {
		gaoneng[i] = gaoneng[i - 1] * 3 + dineng[i - 1] * 2;
		dineng[i] = gaoneng[i - 1] + dineng[i - 1];
	}
	int n;
	while(scanf("%d", &n) && n != -1) {
		printf("%lld, %lld\n", gaoneng[n], dineng[n]);
	}
	
	return 0;
}
