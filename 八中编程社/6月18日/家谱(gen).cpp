#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, string>persons;

string s, t, p;

string zuisu(string x) {
	if (persons[x] == x) {
		return x;
	}
	return persons[x] = zuisu(persons[x]);
}

void f(string x, string y) {
	string xx = zuisu(x);
	if (xx != y) persons[y] = xx;
}

int main() {
	while (cin >> s && s != "$") {
		if (s[0] == '#') {
			t = s.substr(1);
			if (persons[t] == "") {
				persons[t] = t;
			}
		}
		else if (s[0] == '+') {
			p = s.substr(1);
			f(t, p);
		}
		else if (s[0] == '?') {
			p = s.substr(1);
			zuisu(p);
			cout << p << " " << persons[p] << endl;
		}
	}
	return 0;
}
