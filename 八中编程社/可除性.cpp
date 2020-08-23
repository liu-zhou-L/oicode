#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 1e4 + 5;

int t, n, k, s[MAXN];
bool  f[MAXN][105];////f[i][j]��ʾǰi����������֮�������Ƿ�Ϊj

int main() {
	scanf("%d", &t);
	while(t --) {
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &s[i]);
			s[i] = int(fabs(s[i])) % k;//s[i]Ϊ��i��Ԫ��ģk��ֵ 
		}
		memset(f, 0, sizeof(f));//���ǰһ�εļ�¼ 
		f[1][s[1]] = 1;//��ʼ�� 
		for(int i = 2; i <= n; i ++) {
			for(int j = k - 1; j >= 0; j --) {
				if(f[i - 1][j]) {//���ǰi - 1��Ԫ��ģk����j 
					f[i][(j + s[i]) % k] = 1;//��ôǰi-1��ֵ�ĺͼ��ϵ�i��Ԫ��ģk���ڼ��ϵ�i��Ԫ�غ�ģk��ֵ
					f[i][((j - s[i]) % k + k) % k] = 1;//ǰi-1��ֵ�ĺͼ�ȥ��i��Ԫ��ģk��ֵΪj��ȥ��i��Ԫ�غ�ģk�ټ�k��ֵ
				}
			}
		}
		if(f[n][0]) {//�������Ԫ�صĺ��ܷ�k���� 
			printf("Divisible\n");
		}
		else {
			printf("Not divisible\n");
		}
	}
	return 0;
}
