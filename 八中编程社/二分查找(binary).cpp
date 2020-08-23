#include <cstdio>

const int MAXN = 1e6 + 5;

int n, a[MAXN], x;

int find(int head, int last) {
	if(head >= last) {
		if(a[head] == x) {
			return head;
		}
		else {
			return last;
		}
	}
	int mid = (head + last) / 2;
	if(a[mid] >= x && a[head] <= x) {//先判断，能保证为第一次出现的 
		return find(head, mid);
	}
	else if(a[mid + 1] <= x && a[last] >= x) {
		return find(mid + 1, last);
	}
	else return -1;
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

