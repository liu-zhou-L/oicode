#include <cstdio>
#include <cstring> 

const int MAXN = 2505;

int n, m, s, t, a[MAXN][MAXN], f[MAXN];
bool flag[MAXN];

int Min(int i, int j) {
	return i < j ? i : j;
}

void dijkstra() {
	memset(f, 0x3f, sizeof(f));
	memset(flag, 0, sizeof(flag));
	f[s] = 0;
	//flag[s] = 1;
	for (int i = 1; i <= n; i++) {
		int minn = 0x3f3f3f3f;
		int k=0;
		for (int j = 1; j <= n; j++) {
			if (!flag[j]&& f[j] < minn) {
				minn = f[j];
				k=j;
			}
		}
		flag[k] = 1;
		for (int j = 1; j <= n; j++) {
			f[j] = Min(f[j], f[k] + a[k][j]);
		}
	}
	return;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		a[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_, temp;
		scanf("%d%d%d", &tmp, &tmp_, &temp);
		a[tmp][tmp_] = temp;
	}
	dijkstra();
	printf("%d", f[t]);
	return 0;
}

//#include <queue>
//#include <cstdio>
//#include <cstring>
//
//typedef std::pair<int, int> pii;
//
//const int MAXN = 2500, MAXM = 6200;
//int n, m, s, t, ecnt, head[MAXN + 5], dist[MAXN + 5];
//bool vis[MAXN + 5];
//
//struct Edge { int to, cst, nxt; } graph[MAXM * 2 + 5]; 
//
//inline void link ( const int s, const int t, const int c ) {
//	graph[++ ecnt] = { t, c, head[s] };
//	head[s] = ecnt;
//}
//
//inline void Dijkstra ( const int s ) {
//	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > que;
//	memset ( dist, 0x3f, sizeof dist );
//	que.push ( { dist[s] = 0, s } );
//	while ( ! que.empty () ) {
//		pii p = que.top (); que.pop ();
//		if ( vis[p.second] ) continue;
//		vis[p.second] = true;
//		for ( int i = head[p.second], v; i; i = graph[i].nxt ) {
//			if ( ! vis[v = graph[i].to] && dist[v] > p.first + graph[i].cst ) {
//				que.push ( { dist[v] = p.first + graph[i].cst, v } );
//			}
//		}
//	}
//}
//
//int main () {
//	scanf ( "%d %d %d %d", &n, &m, &s, &t );
//	for ( int i = 1, u, v, w; i <= m; ++ i ) {
//		scanf ( "%d %d %d", &u, &v, &w );
//		link ( u, v, w ), link ( v, u, w );
//	}
//	Dijkstra ( s );
//	printf ( "%d\n", dist[t] );
//	return 0;
//}
