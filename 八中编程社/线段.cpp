#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;

struct line {
	int a, b;
} lines[MAXN];

bool cmp(line i, line j) {
	if(i.b == j.b) return i.a > j.a;
	return i.b < j.b;
}

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &lines[i].a, &lines[i].b);
	}
	sort(lines + 1, lines + 1 + n, cmp);
	for(int i = 0; i < n; i ++) {
		for(int j = i + 1; j <= n; j ++) {
			if(lines[j].a >= lines[i].b) {
				sum ++;
				i = j;
			}
		}
	}
	printf("%d", sum);
	return 0;
}

