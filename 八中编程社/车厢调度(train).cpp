#include <cstdio>
#include <stack>
using namespace std;

const int MAXN = 1005;

int n, target[MAXN];
stack<int> s;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &target[i]);
	}
	bool flag = 0;
	int a = 1, b = 1;//i指向a的第i节车厢 ,i=a[i]， j指向b的第j节车厢
	while(b <= n) {//j==n，则移完了 
		if(a == target[b]) {//b所需的车厢在a里 
			a ++;
			b ++;
		}
		else if(s.empty() == 0 && s.top() == target[b]) {//b所需的车厢在c里 
			s.pop();
			b ++;
		}
		else if(a <= n) {//如果均不是，则b所需的车厢在a后面 
			s.push(a ++);
		}
		else {//否则不可能 
			flag = 1;
			break;
		}
	}
	if(flag == 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}

