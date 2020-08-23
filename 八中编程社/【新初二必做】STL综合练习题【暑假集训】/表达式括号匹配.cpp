#include <cstdio>
#include <stack>

using namespace std;

stack<int> st;
char ch;

int main() {
	while ((ch = getchar()) && ch != '@') {
		if (ch == '(') {
			st.push(1);
		} else if (ch == ')') {
			if (!st.empty()) {
				st.pop();
			} else {
				printf("NO");
				return 0;
			}
		}
	}
	if (st.empty()) printf("YES");
	else printf("NO");
	return 0;
}
