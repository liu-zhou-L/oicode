#include <cstdio>
#include <cmath>

int a;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = n; i >= 0; i --) {
		scanf("%d", &a);
		if(a) {
			if(i != n && a > 0) printf("+");
            if(abs(a) > 1 || i == 0) printf("%d", a);
            if(a == -1 && i) printf("-");
            if(i > 1) printf("x^%d", i);
            if(i == 1) printf("x");
		}
	}
	/*bool flag = 0;
	for(int i = n; i >= 0; i --) {
		if(i != 0) {
			if(a[i] < 0) {
				if(a[i] != -1) {
					printf("%dx^%d", a[i], i);
				}
				else {
					printf("-");
					printf("x^%d", i);
				}
				flag = 1;
			}
			else if(a[i] == 0) {
				continue;
			}
			else {
				if(i != n) printf("+");
				if(a[i] != 1) {
					printf("%dx^%d", a[i], i);
				}
				else {
					printf("x^%d", i);
				}
				flag = 1;
			}	
		} 
		else {
			if(a[i] == 0) {
				continue;
			}
			else if(a[i] >= 0 && flag == 1) printf("+");
			printf("%d", a[i]);
		}
	}*/
	return 0;
}

