//×îºó±à¼­
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 2 * 1e4 + 5;

queue<int> que;
int n, operan;
char cmd[10];

int main() {
	/*freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);*/
	scanf("%d\n", &n);
	while(n--) {
		scanf("%s", cmd);
		if(!strcmp(cmd, "push")) {
			scanf("%d", &operan);
			que.push(operan);
		}
		else if(!strcmp(cmd, "empty")) {
			if(que.empty()) {
				printf("empty\n");
			}
			else {
				printf("not empty\n");
			}
		}
		else if(!strcmp(cmd, "clear")) {
			while(!que.empty()) {
				que.pop();
			}
		}
		else if(!strcmp(cmd, "pop")) {
			if(que.size() == 0) {
				printf("error\n");
			}
			else {
				que.pop();
			}
		}
		else if(!strcmp(cmd, "front")) {
			if(que.size() > 0) {
				printf("%d\n", que.front());
			}
			else {
				printf("error\n");
			}
		}
		getchar();
	}
	return 0;
}

