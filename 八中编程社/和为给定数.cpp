#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;

int n, a[MAXN], left, right;

int main() {
	int x;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	a[n + 1] = 999999999;
	scanf("%d", &x);
	int mid;
	for(int i = 1; i <= n; i ++) {
		left = 1;
		right = n + 1;
		int k = x - a[i];
		while(left  + 1 < right) {
			mid = (left + right) / 2;
			if(a[mid] == k) {
				printf("%d %d", x - a[mid], a[mid]);
				return 0;
			}
			else if(a[mid] > k) {
				right = mid;
			}
			else {
				left = mid;
			}
		}
	}
	printf("No");
	return 0;
}

