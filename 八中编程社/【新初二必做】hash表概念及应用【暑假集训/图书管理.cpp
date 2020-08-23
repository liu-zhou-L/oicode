#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int m;
set<string> dict;

int main() {
	scanf("%d", &m);
	string cmd;
	for (int i = 1; i <= m; i++) {
		cin >> cmd;
		getchar();
		if (cmd == "add") {
			getline(cin, cmd);
			dict.insert(cmd);
		} else if (cmd == "find") {
			getline(cin, cmd);
			if (dict.find(cmd) != dict.end()) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
