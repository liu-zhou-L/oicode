#include <cstdio>

const int MAXN = 1e5 + 5;

int n, m, a[MAXN], left = 0, right = 0; 

bool check(int x) {
	int tot = 0, sum = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > x) return false;
		if(tot + a[i] <= x) {
			tot += a[i];
		}
		else {
			tot = a[i];
			sum ++;
		}
	}
	return sum >= m;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		right += a[i];
		if(a[i] > left) left = a[i];//在最大值和总和之间找 
	}
	int mid;
	left --;
	//printf("%d %d\n", left, right);
	while(left + 1 < right) {
		mid = (left + right) / 2;
		if(check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
		//printf("%d %d\n", left, right);
	}
	printf("%d", right);
	return 0;
}

