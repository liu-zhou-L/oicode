#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 105;

int n, in[MAXN];
vector<int> edge[MAXN], ans;
bool vis[MAXN];

void topo() {
	for(int i = 1, len = 1; i <= n && len <= n; i++) {
		int index = -1;
		for(int j = 1; j <= n; j++) {
			if(!vis[j] && in[j] == 0) {
				index = j;		
				vis[index] = true; 
				ans.push_back(index);
				for(int j = 0; j < edge[index].size(); j++) {
					int end = edge[index][j];
					in[end]--;
				}			
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		while (scanf("%d", &temp) && temp != 0) {
			edge[i].push_back(temp);
			in[temp]++;
		}
	}
	topo();
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
