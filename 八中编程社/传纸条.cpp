#include <cstdio>
#include <algorithm>

const int MAXN = 55;

int m, n, a[MAXN][MAXN], f[MAXN][MAXN][MAXN][MAXN];//f[i][j][k][l] Ϊ��ֽ���ֱ𴫵�(i, j),(k, l)�����øж�

int MAX(int i, int j, int k, int l) {
	return std::max(std::max(i, j), std::max(k, l));
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= m; k++) {
				for(int l = 1; l <= n; l++) {//����ö�� 
					f[i][j][k][l] = MAX(f[i - 1][j][k - 1][l],  f[i - 1][j][k][l - 1], f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]) + a[i][j] + a[k][l];
					 //һ��ֽ�������ִ��ݵķ�ʽ������һ�������ַ�ʽ��ȡ�øж�����һ�� 
					if(i == k && j == l) {//����ߵ�һ��λ�� 
						f[i][j][k][l] -= a[i][j];//��ȥ����һ���ĺøж�
					}
				}
			}
		}
	}
	printf("%d", f[m][n][m][n]);
	return 0;
}
