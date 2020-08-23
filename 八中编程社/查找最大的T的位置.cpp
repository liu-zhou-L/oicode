#include <cstdio>
#include <cstring>

const int MAXN = 1e5 + 5;

char a[MAXN];

int find(int head, int last) {
	head --;
	last ++;
	int mid;
	while(head + 1 < last) {
		mid = (head + last) / 2;
		if(a[mid] == 'T') {
			head = mid;
		}
		else {
			last = mid;
		}
	}
	if(last == 0) return -1;
	return last;
}

int main() {
	int n, len;
	scanf("%d", &n);
	while(n --) {
		scanf("%s", a);
		len = strlen(a);
		printf("%d\n", find(0, len - 1));
	}
	return 0;
}

