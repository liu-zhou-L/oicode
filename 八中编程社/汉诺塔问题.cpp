#include<cstdio>
const char a = 'A';
const char b = 'B';
const char c = 'C';
void f(int n, char a,char b,char c) {
    if(n == 1) printf("%c->%c\n", a, c);
    else {
        f(n-1, a, c, b);
        printf("%c->%c\n", a, c);
        f(n-1, b, a, c);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    f(n, a, b, c);
    return 0;
}
