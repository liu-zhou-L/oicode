//×îºó±à¼­20/3/4
#include <cstdio>

const int MAXN = 5 * 1e4 + 5;

int /*m[MAXN][MAXN] = {}, */h0[MAXN] = {}, h2[MAXN] = {};

int main() {
	int n, p1, p2;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &p1, &p2);
		if(p2 != 0) {
			for(int j = n; j >= p2; j --) {
			//	m[i][j] = 2;
				h2[i] ++;
			}
		}
		if(p1 != 0) {
			h0[i] = p1 - 1;
		}
		else {
			if(p2 != 0) {
				h0[i] = p2 - 1;
			}
			else {
				h0[i] = n;
			}
		}
	}
	int maxn = 0, sum = 0;
	for(int i = 1; i <= n; i ++) {
		if(h0[i] != 0) {
			for(int j = 1; j <= h0[i]; j ++) {
				int temp = 0;
				for(int k = i; k >= 1; k --) {
					if(h0[k] >= j) temp += j;
					else break;
				}
				//printf("temp0:%d\n", temp);
				if(maxn < temp) {
					maxn = temp;
					sum = 1;
				}
				else if(maxn == temp) {
					sum ++;
				}	
			}
		}
		if(h2[i] != 0) {
			for(int j = 1; j <= h2[i]; j ++) {
				int temp = 0;
				for(int k = i; k >= 1; k --) {
					if(h2[k] >= j) temp += j;
					else break;
				}
				//printf("temp2:%d\n", temp);
				if(maxn < temp) {
					maxn = temp;
					sum = 1;
				}
				else if(maxn == temp) {
					sum ++;
				}	
			}
		}
	}
	printf("%d\n%d", maxn, sum);
	/*for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			printf("%d ", m[i][j]); 
		}
		printf("\n");
	}*/
	/*for(int i = 1; i <= n; i ++) {
		printf("%d  h0:%d h2:%d\n", i, h0[i], h2[i]); 
	}*/
	return 0;
}
