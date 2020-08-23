#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 2 * 1e5 + 5;

int a[MAXN];

int main() {
	int n, s, mid;
	scanf("%d %d", &n, &s);
	mid = (n + 1) / 2;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	long long sum = s - a[mid];
	a[mid] = s;
	if(sum > 0) {
		for(int i = mid + 1; i <= n; i ++) {
			if(a[i] < a[i - 1]) {
				sum += a[i - 1] - a[i];
				a[i] = a[i - 1];
			}
		}
	}
	else if(sum < 0) {
		sum = -sum;
		for(int i = mid - 1; i >= 1; i --) {
			if(a[i] > a[i + 1]) {
				sum += a[i] - a[i + 1];
				a[i] = a[i + 1];
			}
		}	
	}
	printf("%lld", sum);
	return 0;
}

