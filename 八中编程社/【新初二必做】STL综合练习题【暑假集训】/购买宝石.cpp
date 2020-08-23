#include <cstdio>
#include <vector>

using namespace std;

struct node {
	int v, c;
};

int n, ans = 0;
vector<node> bshi;

int main() {
	scanf("%d", &n);
	bshi.resize(n + 5);
	for (int i = 1; i <= n; i++)
		scanf("%d", &bshi[i].v);
	for (int i = 1; i <= n; i++)
		scanf("%d", &bshi[i].c);
	for (int i = 1; i <= n; i++) {
		if (bshi[i].v > bshi[i].c)
			ans += bshi[i].v - bshi[i].c;
	}
	printf("%d\n", ans);
	/*for (int i = 1; i <= n; i++) {
		printf("%d ", bshi[i].v - bshi[i].c);
	}*/
	return 0;
}
