#include <cstdio>
#include <vector>
using namespace std;

vector<int> s;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		s.push_back(i);
	}
	for(int i = 1; i < n; i ++) {
		printf("%d ", s.front());
		s.erase(s.begin());
		s.push_back(s.front());
		s.erase(s.begin());
	}
	printf("%d", s.front());
	return 0;
}

