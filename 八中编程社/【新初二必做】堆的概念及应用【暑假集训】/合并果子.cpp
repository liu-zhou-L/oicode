#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

int n, heap[MAXN], size = 0, ans = 0;

void Put() {
	int x = size;
	while (x > 1) {
		if (heap[x] < heap[x >> 1]) {
			swap(heap[x], heap[x >> 1]);
			x >>= 1;
		}
		else break;
	}
	return;
}

void Pop() {
	heap[1] = heap[size--];
	int x = 1;
	while (x <= (size >> 1)) {
		int son = x * 2;
		if (son < size && heap[son + 1] < heap[son]) son++;
		if (heap[x] <= heap[son]) break;
		swap(heap[x], heap[son]);
		x = son;
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &heap[++size]); 
		Put();   
	}
	for (int i = 1; i < n; i++) {
		int a = heap[1];
		Pop();
		int b = heap[1];
		Pop();
		ans += a + b;
		heap[++size] = a + b;
		Put();
	}
	printf("%d", ans);
	/*for (int i = 1; i <= n; i++) {
		printf("%d ", heap[i]);
	}*/
	return 0;
}
