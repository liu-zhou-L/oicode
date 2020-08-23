#include<cstdio>

#define LL long long

const char A = 'A';
const char B = 'B';
const char C = 'C';

void f(LL n, char a, char b, char c) {
    if(n == 1) printf("%d %c %c\n", n, a, c);
    else {
        f(n-1, a, c, b);
        printf("%d %c %c\n", n, a, c);
        f(n-1, b, a, c);
    }
}

int main() {
    LL n;
    scanf("%lld", &n);
    f(n, A, C, B);
    return 0;
}
