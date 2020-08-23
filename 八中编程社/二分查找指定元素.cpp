#include <cstdio>

const int MAXN = 1e6 + 5;

int n, a[MAXN], x;

int find(int head, int last) {
	int mid;
	while(head + 1 < last) {//head��last������ 
		mid = (head + last) / 2;
		if(a[mid] == x) {//��Ⱦͷ���mid 
			return mid;
		}
		else if(a[mid] < x) {//С�ڣ�����������ǰ�벿�� 
			head = mid;
		}
		else {//�����ں�벿�� 
			last = mid;
		}
	}
	return x - a[head] <= a[last] - x ? head : last;//���ز�ֵС���� 
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

