#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct node {
	int id;
	int now;
	int period;
	bool operator<(const node &that) const {
		if (this->now == that.now)
			return this->id > that.id;
		return this->now > that.now;
	}
} temp;

int k;
priority_queue<node> que;

int main() {
	string str;
	while ((cin >> str) && str[0] != '#') {
		scanf("%d%d", &temp.id, &temp.period);
		temp.now = temp.period;
		que.push(temp);
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		temp = que.top();
		que.pop();
		//printf("now:%d ", temp.now);
		printf("%d\n", temp.id);
		temp.now += temp.period;
		que.push(temp);
	}
	return 0;
}
