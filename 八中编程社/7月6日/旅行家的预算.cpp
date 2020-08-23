#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 105;

struct node {
	double d;
	double p;
	bool operator<(const node& that) {
		return this->d < that.d;
	}
} station[MAXN];

double d[5], c, p;
int n;
bool flag = false;

int check(int start, double maxl, double s, int &end) {
	int index = -1;
	int i;
	for (i = start; i <= n && station[i].d <= maxl; i++) {
		flag = true;
		if(station[i].p < s) {
			index = i;
			s = station[i].p;
		}
	}
	if (index == -1) end = i - 1;
	return index;
}

int main() {
	scanf("%lf%lf%lf%lf%d", &d[1], &c, &d[2], &p, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &station[i].d, &station[i].p);
	}
	station[n].d = d[1];
	station[n].p = 999;
	sort(station, station + 1 + n);
	int now = 0,//当前车站
	start = 0,
	end;
	double len = 0,//已走距离
	sum = 0,
	sumf = 0;
	const double MAX = c * d[2];//加满油后能走的距离
	while (now < n) {
		int k = check(start, len + MAX, p, end);
		if (k >= n || end >= n || !flag) break;
		if(k == -1) {
			sum += (c * p);
			p = station[end].p;
			sumf += ((len + MAX - station[end].d) * p / d[2]);
			len = station[end].d;
			now = end;
			start = end + 1;
		} else {
			sum += ((station[k].d - len) * p / d[2]);
			p = station[k].p;
			len = station[k].d;
			now = k;
			start = k + 1;
		}
	}
	if (d[1] - len <= MAX) {
		sum += (d[1] - len) * p / d[2];
		flag = true;
	} else flag = false;
	if (flag) printf("%.2lf", sum - sumf);
	else printf("No solution");
	return 0;
}
