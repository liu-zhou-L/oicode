#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1005;

char str_1[MAXN], str_2[MAXN];
int len_1, len_2, f[MAXN][MAXN], prev[MAXN][MAXN];

void point(int i, int j) {
	if(i == 0 || j == 0) {
		return;
	}
    if(prev[i][j] == 1){
        point(i - 1, j - 1);
        printf("%c", str_1[i - 1]);
    }
    else if(prev[i][j] == 2) {
    	point(i - 1, j);
	}
    else {
    	point(i, j - 1);
	}
    return;
}

int main() {
	scanf("%s%s", str_1, str_2);
	len_1 = strlen(str_1);
	len_2 = strlen(str_2);
	for(int i = 1; i <= len_1; i ++) {
		for(int j = 1; j <= len_2; j ++) {
			if(str_1[i - 1] == str_2[j - 1]) {
				f[i][j] = f[i - 1][j - 1] + 1;
				prev[i][j] = 1;
			}
			else if(f[i - 1][j] >= f[i][j - 1]) {
				f[i][j] = f[i - 1][j];
				prev[i][j] = 2;
			}
			else {
				f[i][j] = f[i][j - 1];
				prev[i][j] = 3;
			}
		}
	}
	printf("%d\n", f[len_1][len_2]);
	point(len_1, len_2);
	return 0;
} 
