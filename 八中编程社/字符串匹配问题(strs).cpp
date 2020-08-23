#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

stack<char> s;

int main() {
	int n;
	char a[300];
	scanf("%d", &n);
	while(n --) {
		scanf("%s", a);
		while(!s.empty()) s.pop();
		int i = 0, len = strlen(a);
		bool flag = 1;
		while(i < len) {
			if(a[i] == '}' || a[i] == ']' || a[i] == ')' || a[i] == '>') {
				if(s.empty() != 1) {
					if((a[i] == '}' && s.top() == '{') || (a[i] == ']' && s.top() == '[') || (a[i] == ')' && s.top() == '(') || (a[i] == '>' && s.top() == '<')) {
						s.pop();
					}
				}
				else {
					flag = 0;
					break;
				}
			}
			else {
				if(s.empty() != 1) {
					if((a[i] == '{' && s.top() != '[' && s.top() != '(' && s.top() != '<') ||
					   (a[i] == '[' && s.top() != '(' && s.top() != '<') ||
					   (a[i] == '(' && s.top() != '<') ||
					   a[i] == '<') {
						s.push(a[i]);
					}
					else {
						flag = 0;
						break;
					}
				}
				else {
					s.push(a[i]);
				}
			}
			i ++;
		}
		if(flag == 0 || s.empty() != 1) printf("NO\n");
		else printf("YES\n");
		//printf("%s\n",a);
	}
	return 0;
}
