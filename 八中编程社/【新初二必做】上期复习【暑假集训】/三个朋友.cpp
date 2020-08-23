#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int MAXN = 2000005;

int n, ans = 0;
char s[MAXN];
LL pre[MAXN], hash[MAXN], sumr/*右半边的hash值*/, suml/*左半边的hash值*/;
string str, str_, ans_1, ans_2;

LL Hash(int l,int r) {
	return hash[r] - hash[l - 1] * pre[r - l + 1];
}

LL Sum(int l, int r, int k){
	return Hash(l, k - 1) * pre[r - k] + Hash(k + 1, r);
}

int main() {
	scanf("%d%s", &n, s + 1);
	if (n / 2 == 0) {//只有一个元素 
		printf("NOT POSSIBLE");
		return 0;
	}
	int mid = (n + 1) >> 1;
	pre[0] = 1;
	for (int i = 1; i <= n; i++) {//hash处理 
		pre[i] = pre[i - 1] * 131;
		hash[i] = hash[i - 1] * 131 + (s[i] - 64);
	}
	sumr = Hash(mid + 1, n);
	for (int i = mid + 1; i <= n; i++) {
		str.push_back(s[i]);
	}
	for (int i = 1; i <= mid; i++) {
		suml = Sum(1, mid, i);
		if (suml == sumr) {
			ans++;
			ans_1 = str;
			break;
		}
	}
	suml = Hash(1, mid - 1);
	for (int i = 1; i < mid; i++) {
		str_.push_back(s[i]);
	}
	for (int i = mid; i <= n; i++) {
		sumr = Sum(mid, n, i);
		if (suml == sumr) {
			ans++;
			ans_2 = str_;
			break;
		}
	}
	if (!ans) {
		printf("NOT POSSIBLE");
	}
	else if (ans == 1 || ans_1 == ans_2) {
		cout << (ans_1.size() ? ans_1 : ans_2);
	}
	else {
		printf("NOT UNIQUE");
	}
	return 0;
}
