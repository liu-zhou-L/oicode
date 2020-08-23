#include<cstdio>

int n, a[250], sum;

void f(int x,int index) {
	if(x == 0) {
		sum ++;
		printf("%d=", n);
		for(int i = 1; i < index - 1; i ++) {
			printf("%d+",a[i]);
		}
		printf("%d\n",a[index - 1]);
		return;
	}
	int im = x < n ? x : n;
	for(int i = (a[index - 1] == 0 ? 1 : a[index - 1]); i <= im; i ++) {
		if(i != n) {
			a[index] = i;
			f(x - i, index + 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	f(n, 1);
	printf("%d", sum);
	return 0;
}

