#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

queue<int> s;
int num[MAXN];

int main() {
	int n, k, p, cnt = 1;
	scanf("%d %d %d", &n, &k, &p);
	for(int i = 1; i <= k; i ++) {
		s.push(i);
	}
	int index = 0;
	for(int i = 1; i <= k; i ++) {
		if(index == n) index = 0;
		if(index == n - 1) {
			num[cnt ++] = s.front();
		}
		s.pop();
		for(int j = 1; j <= p; j ++) { 
			int temp = s.front();
			s.pop();
			s.push(temp);
		}
		index ++;
	}
	sort(num + 1, num + cnt);
	for(int i = 1; i < cnt; i ++) {
		printf("%d\n", num[i]);
	}
	return 0;
}
