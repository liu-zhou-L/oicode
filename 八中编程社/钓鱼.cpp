#include<cstdio>

const int MAXN = 105;

struct lake {
	int inin, redn, time, max;
} lakes[MAXN];

int f[MAXN], n, h, now, temp, ans;

int Max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d %d", &n, &h);
	h = h * 60 / 5;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &lakes[i].inin);
	}
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &lakes[i].redn);
	}
	for(int i = 1; i < n; i ++) {
		scanf("%d", &lakes[i].time);
		lakes[i].time += lakes[i - 1].time;
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= i; j ++) f[j] = lakes[j].inin;
		temp = h - lakes[i - 1].time;
		int tt, maxx, sum = 0;
		for(int j = 1; j <= temp; j ++)
		{
			maxx = 0;
			for(int k = 1; k <= i; k ++)
				if(f[k] > maxx) {
					maxx = f[k];
					tt = k;
				}
			if(maxx == 0) break;
			f[tt] -= lakes[tt].redn;
			sum += maxx;
		}
		ans = Max(ans, sum);
	}
	printf("%d", ans);
	return 0;
}

