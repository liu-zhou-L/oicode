#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

int n, heap[MAXN], size = 0;

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
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d", &heap[++size]);
			Put();
		} else if (cmd == 2) printf("%d\n", heap[1]);
		else Pop();
	}
	/*for (int i = 1; i <= n; i++) {
		printf("%d ", heap[i]);
	}*/
	return 0;
}
