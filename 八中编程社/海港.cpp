#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 1e6;

int t[MAXN], k[MAXN], f[MAXN], m, sum = 0, head = 1;

queue<int> s;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &t[i], &k[i]);
		for(int j = 1; j <= k[i]; j ++) {
			scanf("%d", &m);
			if(f[m] == 0) {
				sum ++;
			}
			f[m] ++;
			s.push(m);
		}
		while(t[head] + 86400 <= t[i]) {
			for(int j = 1; j <= k[head]; j ++) {
				f[s.front()] --;
				if(f[s.front()] == 0) {
					sum --;
				}
				s.pop();
			}
			head ++;
		}
		printf("%d\n", sum);
	}
	return 0;
}
