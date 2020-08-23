#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 50005;

int k, in[50], cnt = 0;
char s[MAXN][105], str[105], ans[105];
bool sum[50];
vector<int> edge[50];
map<char, char> dict;

int main() {
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		scanf("%s", s[i]);
	}
	scanf("%s", str);
	for (int i = 2; i <= k; i++) {
		int len = min(strlen(s[i]), strlen(s[i - 1]));
		for (int j = 0; j < len; j++) {
			if (s[i][j] != s[i - 1][j]) {
				edge[s[i - 1][j] - 64].push_back(s[i][j] - 64);
				in[s[i][j] - 64]++;
				sum[s[i][j] - 64] = true;
				sum[s[i - 1][j] - 64] = true;
				break;
			}
		}
	}
	for (int i = 1; i <= k; i++) {
		if (sum[i] != 0) {
			cnt++;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		int j = 1;
		while (j <= 26 && (in[j] || sum[j] == 0)) j++;
		if (j > 26) {
			printf("0");
			return 0;
		}
		dict[j + 64] = 64 + i;
		in[j] = -1;
		for (int k = 0; k <= edge[j].size() - 1; k++) {
			in[edge[j][k]]--;
		}
	}
	int len = strlen(str);
	for (int i = 0; i <= len - 1; i++) {
		if (dict[str[i]] == 0) {
			printf("1");
			return 0;
		}
		ans[i] = dict[str[i]];
	}
	for (int i = 0; i <= len - 1; i++) {
		printf("%c", ans[i]);
	}
	return 0;
}
