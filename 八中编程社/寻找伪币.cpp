#include <cstdio>

int a[20];

int sum(int head, int last) {
	int ans = 0;
	while(head <= last) {
		ans += a[head ++];
	}
	return ans;
}

int f(int head, int last) {
	if(last - head == 1) {
		//printf("%d\n", a[head] < a[last] ? a[head] : a[last]);
		return a[head] < a[last] ? head : last;
	}
	int mid = (head + last) / 2;
	if(sum(head, mid) > sum(mid + 1, last)) {
		//printf("%d %d\n", mid + 1, last);
		return f(mid + 1, last);
	}
	else {
		//printf("%d %d\n", head, mid);
		return f(head, mid);
	}
}

int main() {
	for(int i = 1; i <= 16; i ++) {
		scanf("%d", &a[i]);
	}
	int index = f(1, 16);
	printf("%d %d", index, a[index]);
	return 0;
}

