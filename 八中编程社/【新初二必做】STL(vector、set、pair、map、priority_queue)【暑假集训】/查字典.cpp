#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<string, int> Dict;

int n, m;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		string tmpstr;
		cin >> tmpstr >> temp;
		Dict[tmpstr] = temp;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		string tmpstr;
		cin >> tmpstr;
		printf("%d\n", Dict[tmpstr]);
	}
	return 0;
}
