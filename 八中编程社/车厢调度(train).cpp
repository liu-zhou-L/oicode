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
	int a = 1, b = 1;//iָ��a�ĵ�i�ڳ��� ,i=a[i]�� jָ��b�ĵ�j�ڳ���
	while(b <= n) {//j==n���������� 
		if(a == target[b]) {//b����ĳ�����a�� 
			a ++;
			b ++;
		}
		else if(s.empty() == 0 && s.top() == target[b]) {//b����ĳ�����c�� 
			s.pop();
			b ++;
		}
		else if(a <= n) {//��������ǣ���b����ĳ�����a���� 
			s.push(a ++);
		}
		else {//���򲻿��� 
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

