#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10005;

int maxn = 0, a[MAXN], len, str_len, r, ans = -1;
string str;

int check(int x) {
	int ret = 0;
	for (int i = 1; i <= len; i++) {
		if(a[i] >= x) {
			ret += x;
		}
	}
	return ret;
}

int main() {
	while (getline(cin, str, '\n')) {
		len = 0;
		int temp = 0;
		r = 0;
		maxn = 0;
		for (int i = 1; i <= str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9')
				temp = temp * 10 + (str[i] - '0');
			else {
				a[++len] = temp;
				r = max(r, temp);
				temp = 0;
			}
		}
		for (int i = 1; i <= r; i++) {
			maxn = max(maxn, check(i));
		}
		printf("%d\n", maxn);
		if (getchar() == EOF) break;
	}
	return 0;
}
