#include<cstdio>

int n, k, a[250], sum = 0;

void f(int x,int index) {
	if(x == 0) {
		sum ++;
		return;
	}
	int im = x < k ? x : k;
	for(int i = (a[index - 1] == 0 ? 1 : a[index - 1]); i <= im; i ++) {
		a[index] = i;
		f(x - i, index + 1);
	}
}

int main() {
	scanf("%d %d", &n, &k);
	f(n, 1);
	printf("%d", sum);
	return 0;
}

