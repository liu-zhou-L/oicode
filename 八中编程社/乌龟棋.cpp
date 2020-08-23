#include <cstdio>
#include <algorithm>

using namespace std; 

const int MAXN = 130;

int n, m, card[10], a[MAXN], f[25][25][25][25];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	} 
	int temp;
	for(int i = 1; i <= m; i ++) {
		scanf("%d", &temp);
		card[temp] ++;
	} 
	f[0][0][0][0] = a[1];
	
	for(int i = 0; i <= card[1]; i ++) {
		for(int j = 0; j <= card[2]; j ++) {
			for(int k = 0; k <= card[3]; k ++) {
				for(int l = 0; l <= card[4]; l ++) {
					int t = 1 + i + j * 2 + k * 3 + l * 4;
                	if(i > 0) f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l] + a[t]); 
                	if(j > 0) f[i][j][k][l] = max(f[i][j][k][l], f[i][j - 1][k][l] + a[t]);
                	if(k > 0) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k - 1][l] + a[t]);
                	if(l > 0) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l - 1] + a[t]);
					//f[i][j][k][l] += a[(i + j * 2 + k * 3 + l * 4 + 1)];
				}
			}
		}
	}
	printf ("%d", f[card[1]][card[2]][card[3]][card[4]]);
	return 0;
}
