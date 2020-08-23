//¶Ô¶¥Õ» 
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 10005;

stack<int> s1,s2;
int  a[MAXN] = {}, f[MAXN] = {}, Q, operand, index = 0;
char operators[5];

int main() {
	scanf("%d", &Q);
	while(Q --) {
		getchar();
		scanf("%s", operators);
		if(operators[0] == 'I') {
			scanf("%d", &operand);
			s1.push(operand);
			index ++;
			a[index] = a[index - 1] + operand;
			f[index] = max(a[index], f[index - 1]);
		}
		else if(operators[0] == 'D') {
			if(s1.empty() == 0) {
				index --;
				s1.pop();
			}
		}
		else if(operators[0] == 'L') {
			if(s1.empty() == 0) {
				index --;
				s2.push(s1.top());
				s1.pop();
			}
		}
		else if(operators[0] == 'R') {
			if(s2.empty() == 0) {
				index ++;
				a[index] = a[index - 1] + s2.top();
				f[index] = max(a[index], f[index - 1]);
				s1.push(s2.top());
				s2.pop();
			}
		}
		else if(operators[0] == 'Q') {
			scanf("%d", &operand);
			printf("%d\n", f[operand]);
		}
	}
	return 0;
}

