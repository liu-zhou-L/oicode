/*#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = (2 * 1e6) +5;

int clocks[MAXN], a[MAXN],sum = 0;

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1 ; i <= n; i ++) {
		scanf("%d", &clocks[i]);
	}
	if(k == 1) {
		printf("%d", n);
		return 0;
	}
	a[1] = 1;
	sort(clocks + 1, clocks + 1 + n);
	for(int i = 2; i <= n; i ++) {
		if(clocks[i] - clocks[i - 1] + 1 > m) {
			a[i] = a[i - 1] + 1;
		}
		else {
			bool flag = 1;
			for(int j = i - 1; j >= 0; j --) {
				if(clocks[i] - clocks[j] + 1 > m || j == 0) {
					if(a[i - 1] - a[j] + 1 >= k) {
						flag = 0;
						sum ++;
					}
					break;
				}
			}
			if(flag) {
				a[i] = a[i - 1] + 1;
			}
			else {
				a[i] = a[i - 1];
			}
		}
	}
	printf("%d", sum);
	return 0;
}*/
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = (2 * 1e6) +5;

int clocks[MAXN], s[MAXN], sum = 0, max = 0;

int main() {
	int n, m, k, a;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a);
		clocks[a] ++;
		if(a > max) max = a;
	}
	if(k == 1) {
		printf("%d", n);
		return 0;
	}
	for(int i = 1; i <= max; i ++) {
		if(i < m) {
			s[i] = s[i - 1] + clocks[i];
		}
		else {
			for(int j = 0; j < m; j --) {
				s[i] += clocks[i - j];
			}
		}
	}
	for(int i = 1; i <= max; i ++) {
		
	}
	return 0;
}
