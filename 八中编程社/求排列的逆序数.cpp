#include <cstdio>

const int MAXN = 3 * 1e5 + 5;

long long sum = 0;

long long nodes[MAXN], copy[MAXN];

void Merge_sort(long long head, long long last) {
	if(head == last) return;
	int mid = (last + head) / 2;
	Merge_sort(head, mid);
	Merge_sort(mid + 1, last);
	long long i, j, k;
	i = k = head;
	j = mid + 1;
	while(i <= mid && j <= last) {
		if(nodes[i] <= nodes[j]) {
			copy[k ++] = nodes[i ++];
		}
		else {
			sum += mid - i + 1;
			copy[k ++] = nodes[j++];
		}
	}
	while(i <= mid) {
		copy[k ++] = nodes[i ++];
	}
	while(j <= last) {
		copy[k ++] = nodes[j++];
	}
	for(long long l = head; l <= last; l ++) {
		nodes[l] = copy[l];
	}
}

int main() {
	long long n;
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i ++) {
		scanf("%lld", &nodes[i]);
	}
	Merge_sort(1, n);
	printf("%lld", sum);
	return 0;
}

