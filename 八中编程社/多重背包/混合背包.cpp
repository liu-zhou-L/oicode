#include <cstdio>
#include <algorithm>

const int MAXN = 1005;

int n, v, vol, p, num, sum, f[MAXN];

struct wup {
	int v, p, s;
}wps[MAXN * 10];

int main() {
	scanf("%d%d", &n, &v);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &vol, &p, &num);
		if (num <= 0) {
			sum++;
			wps[sum].v = vol;
			wps[sum].p = p;
			wps[sum].s = num; 
		}
		else {
			for (int j = 1; j <= num; j <<= 1) {
				sum++;
				wps[sum].v = vol * j;
                wps[sum].p = p * j;
                wps[sum].s = -1;
				num -= j;
			}
			if(num) {
				wps[sum].v = vol * num;
            	wps[sum].p = p * num;
            	wps[sum].s = -1;
			}
		}
	}
	for (int i = 1; i <= sum; i++) {
		if (wps[sum].s) {
			for (int j = v; j >= wps[i].v; j--) {
	        	f[j] = std::max(f[j], f[j - wps[i].v] + wps[i].p);
			} 
		}
	    else {
	       	for (int j = wps[i].v; j <= v; j++) {
				f[j] = std::max(f[j], f[j - wps[i].v] + wps[i].p);
			} 
		} 
	}
	printf("%d\n", f[v]);
	return 0;
}
