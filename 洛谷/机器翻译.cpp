#include <cstdio>
#include <queue>

using std::queue;

queue<int> a;
int flag[1005] = {};

int main() {
	int m, n, b, sum = 0;
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &b);
		if(flag[b] == 0) {
			flag[b] ++;
			a.push(b);
			sum ++;
		}
		if(a.size() > m) {
			flag[a.front()] --;
			a.pop();
		}
	}
	printf("%d", sum);
	return 0;
}

