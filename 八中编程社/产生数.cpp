#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 1e7 + 5;

queue<int> p;//��� 

int a[20], b[20];//��� 
bool book[MAXN];//��� 

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= k; i ++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	
	return 0;
}

