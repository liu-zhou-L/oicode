#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN1 = 1e6 + 5;
const int MAXN2 = 1e5 * 7 + 5;

int n;
int ans=0;

struct homeworks {
	int credit;
	int term;
} a[MAXN1];

struct flag {
	bool f;
	int j;
} flags[MAXN2];

bool cmp(homeworks i, homeworks j) {
	if(i.credit == j.credit) return i.term < j.term;
	return i.credit > j.credit;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i].term, &a[i].credit);
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i ++) {
		for(int j = a[i].term; j >= 1; j --) {
			if(flags[j].j != 0) j = flags[j].j;
	        else if(flags[j].f == 0) {
	        	flags[j].f = 1;
	        	ans += a[i].credit;
				int t = j;
				while(flags[t + 1].f == 1) {
					flags[++ t].j = j;
				}
	        	break;
	        }
	    }
	}
	printf("%d", ans);
	return 0;
}
