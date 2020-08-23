#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;
vector<string> line;
stack<string> chudui;
string temp;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		line.push_back(temp);
	}	
	for (int i = 1; i <= m; i++) {
		cin >> temp;
		if (temp == "buy") {
			chudui.push(line.front());
			line.erase(line.begin());
		}
		else if (temp == "back") {
			line.push_back(chudui.top());
			chudui.pop();
		}
		else if (temp == "new") {
			cin >> temp;
			line.push_back(temp);
		}
	}
	for (vector<string>::iterator it = line.begin(); it != line.end(); it++)
		cout << *it << endl;
	return 0;
}
