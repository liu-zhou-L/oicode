#include <cstdio>

const int MAXN = 1e6 + 5;

int n, a[MAXN], x;

int find(int head, int last) {
	head --;
	last ++;//������������ 
	int mid;
	while(head + 1 < last) {//head��last������ 
		mid = (head + last) / 2;
		if(a[mid] >= x) {//���ڵ��ڣ�����������ǰ�벿�� 
			last = mid;
		}
		else {//�����ں�벿�� 
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
