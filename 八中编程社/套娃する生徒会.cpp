#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

#define LL long long

const int MAXN = 2 * 1e6 + 5;

struct matrioska {
	LL b, in, out;
} matrioskas[MAXN];

bool cmp (matrioska i, matrioska j) {
	return i.b > j.b;
}

multiset<LL> s;
multiset<LL>::iterator temp = s.begin();

int main() {
	LL n, ans = 0;
	scanf("%lld", &n);
	for(LL i = 1; i <= n; i ++) {
		scanf("%lld %lld %lld", &matrioskas[i].out, &matrioskas[i].in, &matrioskas[i].b);
		if(matrioskas[i].out <= matrioskas[i].in) {
			swap(matrioskas[i].out, matrioskas[i].in);
		}
		ans += matrioskas[i].in * matrioskas[i].b;
		s.insert(matrioskas[i].out);
	}
	sort(matrioskas + 1, matrioskas + 1 + n, cmp);
	for(LL i = 1; i <= n; i ++) {
		temp = s.lower_bound(matrioskas[i].in);//查找符合条件的套娃
		if(temp != s.begin()) {
			temp --;
			ans -= matrioskas[i].b * (*temp);
       		s.erase(temp);
		}
	}
	printf("%lld", ans);
	return 0;
}
