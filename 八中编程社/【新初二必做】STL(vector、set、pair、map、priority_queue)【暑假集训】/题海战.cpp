#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 105;

int m, n, k;
set<int> stu[MAXN], lib;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		stu[i].clear();
		int p;
		cin >> p;
		for (int j = 1; j <= p; j++) {
			int temp;
			cin >> temp;
			stu[i].insert(temp);
		}
	}
	for (int i = 1; i <= m; i++)
		lib.insert(i);
	cin >> k;
	for (int i = 1; i <= k; i++) {
		set<int> ans = lib;
		int q, z, type;
		cin >> type >> q;
		if (type == 1) {
			for (int j = 1; j <= q; j++) {
				cin >> z;
				for (set<int>::iterator it = ans.begin(); it != ans.end();) {
					if (stu[z].find(*it) == stu[z].end())
						ans.erase(it++);
					else
						it++;
				}
			}
			for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
				cout << *it << " ";
			cout << endl;
		} else {
			for (int j = 1; j <= q; j++) {
				cin >> z;
				for (set<int>::iterator it = ans.begin(); it != ans.end();) {
					if (stu[z].find(*it) != stu[z].end())
						ans.erase(it++);
					else
						it++;
				}
			}
			for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
				cout << *it << " ";
			cout << endl;
		}
	}
	return 0;
}
