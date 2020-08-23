#include<cstdio>
#include<algorithm>
using namespace std;

struct product {
	int a, b;
} pts[105];

bool cmp(product i, product j) {
	if(i.a == i.a) return i.b < j.b;
	else return i.a > j.a;
}

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &pts[i].a, &pts[i].b);
	}
	sort(pts + 1, pts + 1 + n, cmp);
	int s = 0;
	for(int i = 2; i <= n; i ++) {
		if()
	}
	return 0;
}
