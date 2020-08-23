#include <cstdio>

const int MAXN = 1e6 + 5;

int n, a[MAXN], x;

int find(int head, int last) {
	head --;
	last ++;//���ܲ����� 
	int mid;
	while(head + 1 < last) {//head��last������ 
		mid = (head + last) / 2;
		if(a[mid] <= x) {
			head = mid;
		}
		else {
			last = mid;
		}
	}
	return head;//�����ڷ���0 
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
