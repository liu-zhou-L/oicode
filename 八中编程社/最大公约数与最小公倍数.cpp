#include<cstdio>

int main() {
    long long a, b, c, d, e;
    while(scanf("%lld%lld", &a, &b) != EOF) {
	    d = a;
		e = b;
	    while(b != 0) {
	        c = a % b;
	        a = b;
	        b = c;
	    }
	    printf("%lld %lld\n", a, d / a * e / a * a);	
	}
	return 0;
} 
