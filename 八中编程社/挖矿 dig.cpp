#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 75;

struct gren {
	char name[25];
	int k, m, tot;
	gren() { tot = 0; }
	bool operator < (const gren &t) const{
        return this -> tot > t.tot;
    }
} grens[MAXN];

int n, ans = 0;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("\n%s\n%d %d", grens[i].name, &grens[i].k, &grens[i].m);
	}
	while(1) {
		bool flag = 0;
		for(int i = 1; i <= n; i ++) {
			if(grens[i].m >= grens[i].k) {
				flag = 1;
				grens[i].m -= grens[i].k;
				grens[i].m += 2;
				grens[i].tot ++;
			}
		}
		if(!flag) break;
	}
	for(int i = 1; i <= n; i ++) {
		ans += grens[i].tot;
	}
	sort(grens + 1, grens + 1 + n);
	printf("%d\n%s", ans, grens[1].name);
	return 0;
}
