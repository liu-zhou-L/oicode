#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<string, int> Dict;
int n;

int main() {
	while (scanf("%d", &n) && n) {
		Dict.clear();
		for (int i = 1; i <= n; i++) {
			string tmp;
			cin >> tmp;
			Dict[tmp]++;
		}
		string maxn;
		for (map<string, int>::iterator it = Dict.begin(); it != Dict.end(); it++) {
			pair<string, int> temp = (*it);
			if (it == Dict.begin())
				maxn = temp.first;
			else {
				if (temp.second > Dict[maxn])
					maxn = temp.first;
			}
		}
		cout << maxn << endl;
	}
	return 0;
}
