#include <cstdio>//并查集 

const int MAXN = 105;

struct member {
	int source, sum;//source表示当前人所属家族的老大 ,sum表示这个人及以下的人数
	member() {
		sum = 1;
	}
} family[MAXN]; 

int sources(int f) { // 找家族老大 
	if(family[f].source == f) {
		return f;
	}
	else {
		return family[f].source = sources(family[f].source);
	}
}

void merge(int f, int s) { //合并两个家族 
	int s1, s2;
	s1 = sources(family[f].source);
	s2 = sources(family[s].source);
	if(s1 != s2) {
		family[s].source = s1;
		family[s1].sum += family[s2].sum;
	}
	return;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++) {
		family[i].source = i;
	}
	int x, y;
	for(int i = 1; i <= k; i ++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	int sum = 0, max = -1;
	for(int i = 1; i <= n; i ++) {
		if(family[i].source == i) {
			sum ++;
			if(family[i].sum > max) {
				max = family[i].sum;
			}
		} 
	}
	printf("%d %d", sum, max);
	return 0;
}

