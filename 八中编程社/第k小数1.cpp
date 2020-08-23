#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;

int a[MAXN], b[MAXN], n, k;

void f(int left, int right) {
	if(left == right && left == k) return;
	int mid = b[left];
	int i = left, j = right;
	while(i < j) {
		while(b[j] >= mid && i < j) j --;
		while(b[i] <= mid && i < j) i ++;
		if(i == j) break;
		else{
			swap(b[i], b[j]);
		}
	}
	swap(b[left], b[i]);
	if(i > k) {
		f(left, i - 1);
	}
	else if(i < k){
		f(i + 1, right);
	}
	else {
		return;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	f(1, n);
	for(int i = 1; i <= n; i ++) {
		if(a[i] == b[k]) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}

