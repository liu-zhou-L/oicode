#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

map<string, string> dict;
string s, a, b;

int main() {
	while (getline(cin, s) && s != "") {
		a = s.substr(0, s.find(' ')); 
		b = s.substr(s.find(' ') + 1, s.size()); 
		dict[b] = a;
	}
	while (getline(cin, s)) {
		if (dict[s] == "") {
			printf("eh\n");
		} else {
			cout << dict[s] << endl;
		}
	}
	return 0;
}
