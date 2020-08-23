#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1005;

struct node {
	string name;
	vector<string> history;
};

vector<node> v;

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		string temp, web;
		cin >> temp >> web;
		bool flag = false;
		vector<node>::iterator it;
		for (it = v.begin(); it != v.end(); it++) {
			if ((*it).name == temp) {
				(*it).history.push_back(web);
				flag = true;
				break;
			}
		}
		if (!flag) {
			node T;
			T.name = temp;
			T.history.clear();
			T.history.push_back(web);
			v.push_back(T);
		}
	}
	vector<node>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << (*it).name;
		vector<string>::iterator itj;
		for (itj = (*it).history.begin(); itj != (*it).history.end(); itj++) {
			cout << " " << *itj;
		}
		cout << endl;
	}
	return 0;
}

/*#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1005;

struct node {
	string name;
	vector<string> history;
};

vector<node> v;

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		string temp, web;
		cin >> temp >> web;
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].name == temp) {
				v[i].history.push_back(web);
				flag = true;
				break;
			}
		}
		if (!flag) {
			node T;
			T.name = temp;
			T.history.clear();
			T.history.push_back(web);
			v.push_back(T);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << v[i].name;
		for (int j = 0; j < v[i].history.size(); j++) {
			cout << " " << v[i].history[j];
		}
		cout << endl;
	}
	return 0;
}*/
