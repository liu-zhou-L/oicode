#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e4 * 5 + 5;

struct student {
	int a, b;
} students[MAXN];


bool cmp(student i, student j) {
	return j.a - i.b >= i.a - j.b;
}

int main() {
	int n, sum = 0, max;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &students[i].a, &students[i].b);
	}
	sort(students + 1, students + 1 + n, cmp);
	max = - students[1].b;
	for(int i = 1; i <= n; i ++) {
		if(sum - students[i].b > max) max = sum - students[i].b;
		sum += students[i].a;
	}
	printf("%d", max);
	return 0;
}

