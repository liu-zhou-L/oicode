//×îºó±à¼­
#include <cstdio>

const int MAXN = 55;

class Stack {
	private:
		char num[MAXN];
		int last;
	public:
		void clear() {
			Stack::last = 0;
		}
		bool empty() {
			if(Stack::last == 0) return 1;
			return 0;
		}
		void push(char x) {
			Stack::num[Stack::last ++] = x;
		}
		int pop() {
			if(Stack::last == 0) return -1;
			Stack::last --;
			return 0;
		}
		char top() {
			if(Stack::last == 0) return -1;
			return Stack::num[Stack::last - 1];
		}
		int size() {
			return last;
		}
		Stack() {
			Stack::last = 0;
		}
};

Stack a;
int sumblue = 0, ans = 0;

int main() {
	int n;
	char s[MAXN];
	scanf("%d\n%s", &n, s);
	for(int i = n - 1; i >= 0; i --) {
		a.push(s[i]);
		if(s[i] == 'B') sumblue ++;
	}
	while(sumblue > 0) {
		while(a.top() == 'R') {
			a.pop();
		}
		if(a.empty()) break;
		a.pop(), sumblue --, a.push('R');
		while(a.size() < n) sumblue ++, a.push('B');
		ans ++;
	}
	printf("%d", ans);
	return 0;
}

