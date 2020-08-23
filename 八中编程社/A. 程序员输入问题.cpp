#include <cstdio>
#include <stack>
using namespace std;

stack<char> s;

int main() {
	char a, st[105];
	while((a = getchar()) != EOF) {
		if(a == '@') {
			while(!s.empty()) {
				s.pop();
			}
		}
		else if(a == '#') {
			s.pop();
		}
		else {
			s.push(a);
		}
	}
	int len = s.size();
	for(int i = 1; !s.empty(); i ++) {
		st[i] = s.top();
		s.pop();
	}
	for(int i = len; i >= 1; i --) {
		printf("%c", st[i]);
	}
	//printf("%s", st);
	/*while(!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}*/
	return 0;
}

