#include<cstdio>
#include<algorithm>
using namespace std;

struct activity {
	int s, f;
} activities[1005];

bool cmp(activity i, activity j) {
	if(i.f == j.f) i.s > j.s;
	return i.f < j.f;
}

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &activities[i].s, &activities[i].f);
	}
	sort(activities + 1, activities + 1 + n, cmp);
	for(int i = 0; i < n; i ++) {
		for(int j = i + 1; j <= n; j ++) {
			if(activities[j].s >= activities[i].f) {
				sum ++;
				i = j;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
