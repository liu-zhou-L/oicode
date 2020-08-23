#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 205; 

int n, a, b, c[MAXN], f[MAXN];//c¥������ f·�� 
int book[MAXN];//book[i]Ϊa��i�Ĳ��� 

int main() {
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &c[i]);
	}
	f[1] = a;
	book[a] = 1;
	int now;
	for(int i = 1, j = 1; i <= j; i ++) { // jΪ��ǰ��ť���� 
		now = c[f[i]] + f[i];
		if(now <= n && book[now] == 0) {
			book[now] =  book[f[i]] + 1;
			f[++j] = now;
		}
		now = f[i] - c[f[i]]; 
		if(now >= 1 && book[now] == 0) {
			book[now] =  book[f[i]] + 1;
			f[++j] = now;
		}
	}
	printf("%d", book[b] - 1);
	return 0;
}

