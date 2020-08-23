// 2020/02/09
// C++
#include<cstdio>

int N,n;

/*bool zs(int s) {
	for(int i = 2; i * i <= s; i ++) {
		if(s % i == 0) return 0;
	}
	return 1;
}*/

int f(int s, int max) {
	if(s == 1) return 1;
	if(max == 1) return 0;
	if(s % max == 0) return f(s, max - 1) + f(s / max, max);  
	return f(s, max-1);  
}

int main() {
    scanf("%d", &N);
    while(N --) {
    	scanf("%d", &n);
    	printf("%d\n", f(n, n));
	}
    return 0;
}
