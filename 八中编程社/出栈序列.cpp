#include <cstdio>
#include <stack>
using namespace std;

const int MAXN = 1e3 + 5;

stack<int> b;

int c[MAXN];

int main() {
	int n, t;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &c[i]);
	}
	int ina = 1, inc = 1;
	while(inc <= n) {
		if(ina == c[inc]) {
			ina ++;
			inc ++;
		}
		else if(!b.empty() && b.top() == c[inc]) {
			b.pop();
			inc ++;
		}
		else if(ina <= n){
			b.push(ina ++);
		}
		else {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}

