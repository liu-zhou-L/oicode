#include <cstdio>

const int MAXN = 1e5 + 5;

int n, m;
double a[MAXN], x;

int find(int head, int last) {
	int mid;
	head --;
	while(head + 1 < last) {
		mid = (head + last) / 2;
		if(a[mid] == x) return mid;
		if(a[mid] > x) {
			last = mid;
		}
		else {
			head = mid;
		}
	}
	if(head == 0) return -1;
	return head;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%lf", &a[i]);
	}
	for(int i = 1; i <= m; i ++) {
		scanf("%lf", &x);
		int now = find(0, n + 1);
		if(now == -1) printf("NO\n");
		else printf("%d %.2lf\n", now, a[now]);
	}
	return 0;
}

