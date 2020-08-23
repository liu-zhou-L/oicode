#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;

const long long MAXN = 1e4 + 5;

stack<long long> a;
stack<char> b;

long long len;
char expression[MAXN];

int lev(char x)//运算符优先级
{
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}

long long read(int head) {//从字符串中读数
	long long ans = 0;
	int last = head;
	while(expression[last] <= '9' && expression[last] >= '0') last ++;
	for(int i = last - 1; i >= head; i --) {
		ans += (expression[i] - '0') * pow(10, last - i - 1);
	}
	return ans;
}

void calculate() { //计算
	long long x, y;
	char z;
	x = a.top();
	a.pop();
	y = a.top();
	a.pop();
	z = b.top();
	b.pop();
	if(z == '+') {
		a.push(x + y);
	}
	else if(z == '-') {
		a.push(y - x);
	}
	else if(z == '*') {
		a.push(x * y);
	}
	else if(z == '/') {
		a.push(y / x);
	}
	else if(z == '^') {
		a.push(pow(y, x));
	}
}

int main() {
	scanf("%s", expression);
	len = strlen(expression);
	for(int i = 0; i < len; i ++) {
		if(expression[i] <= '9' && expression[i] >= '0') {
			a.push(read(i));
			while(expression[i] <= '9' && expression[i] >= '0') i ++;
			i --;
		}
		else {
			if(expression[i] == '(') {
				b.push(expression[i]);
			}
			else if(expression[i] == ')') {
				while(b.top() != '(') {
					calculate();
				}
                b.pop();
			}
			else {
				while(b.empty() == 0 && lev(b.top()) >= lev(expression[i]))//优先级判断
	                calculate();
	            b.push(expression[i]);
			}
		}
	}
	while(b.empty() == 0)
        calculate();
	printf("%lld", a.top());
	//printf("%d", read(0));
	return 0;
}
