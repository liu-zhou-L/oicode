#include<cstdio>
#include<algorithm>
using namespace std;

int sum = 0;
bool v[30005];

struct conclusion {
	int b, e, t;
} cons[5005];

bool cmp(conclusion i, conclusion j) {
	if (i.e != j.e) return i.e < j.e;
	else return i.b < j.b;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d %d", &cons[i].b, &cons[i].e, &cons[i].t);
	}
	sort(cons + 1, cons + 1 + m, cmp);
	for(int i = 1; i <= m; i ++) {
		for(int j = cons[i].e; j >= cons[i].b; j --) {
			if(cons[i].t > 0 && ! v[j]) {
				v[j] = 1;
				sum ++;
				for(int k = i; k <= m; k ++) {
					if(j >= cons[k].b && j <= cons[k].e) {
						cons[k].t --;
					}
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}
