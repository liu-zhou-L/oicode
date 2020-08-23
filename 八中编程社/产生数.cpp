#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 1e7 + 5;

queue<int> p;//组合 

int a[20], b[20];//配对 
bool book[MAXN];//标记 

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= k; i ++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	
	return 0;
}

