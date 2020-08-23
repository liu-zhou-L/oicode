#include<cstdio>
#include<cmath>

int a, b, c;

double f() {
	char str[10];
	scanf("%s", str);
	if(str[0] == '+') return f() + f();
	else if(str[0] == '-') return f() - f();
	else if(str[0] == '*') return f() * f();
	else if(str[0] == '/') return f() / f();
	else return atof(str);
}

int main() {
	printf("%lf", f());
	return 0;
}
