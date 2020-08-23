#include <cstdio>

const int MAXN = 1e6 + 5;

int n, a[MAXN], x;

int find(int head, int last) {
	head --;
	last ++;//可能在区间外 
	int mid;
	while(head + 1 < last) {//head，last不相邻 
		mid = (head + last) / 2;
		if(a[mid] >= x) {//大于等于，则所求数在前半部分 
			last = mid;
		}
		else {//否则，在后半部分 
			head = mid;
		}
	}
	return last;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &x);
	printf("%d", find(1, n));
	return 0;
}
