#include <cstdio>
#include <cstring>

const char CLEAR[] = "clear";
const char EMPTY[] = "empty";
const char PUSH[] = "push";
const char POP[] = "pop";
const char TOP[] = "top";

class stack {
	private:
		int num[int(2 * 1e5 + 5)];
		int last;
	public:
		void clear() {
			stack::last = 0;
		}
		bool empty() {
			if(stack::last == 0) return 1;
			return 0;
		}
		void push(int x) {
			stack::num[stack::last ++] = x;
		}
		int pop() {
			if(stack::last == 0) return -1;
			stack::last --;
			return 0;
		}
		int top() {
			if(stack::last == 0) return -1;
			return stack::num[stack::last - 1];
		}
		stack() {
			stack::last = 0;
		}
};

int n, b;
char command[10];
stack a;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", command);
		if(strcmp(command, CLEAR) == 0) {
			a.clear();
		}
		else if(strcmp(command, EMPTY) == 0) {
			if(a.empty() == 1) {
				printf("empty\n");
			}
			else {
				printf("not empty\n");
			}
		}
		else if(strcmp(command, PUSH) == 0) {
			scanf("%d", &b);
			a.push(b);
		}
		else if(strcmp(command, POP) == 0) {
			if(a.pop() == -1) {
				printf("error\n");
			}
		}
		else if(strcmp(command, TOP) == 0) {
			b = a.top();
			if(b == -1) {
				printf("error\n");
			}
			else {
				printf("%d\n", b);
			}
		}
	}
	return 0;
}

