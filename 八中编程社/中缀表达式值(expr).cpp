#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;

const long long MAXN = 1e6 + 5;

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
	if(expression[head] == '-')  {
		head ++;
		int last = head;
		while(expression[last] <= '9' && expression[last] >= '0') last ++;
		for(int i = last - 1; i >= head; i --) {
			ans += (expression[i] - '0') * pow(10, last - i - 1);
		}
		return -ans;
	}
	else {
		int last = head;
		while(expression[last] <= '9' && expression[last] >= '0') last ++;
		for(int i = last - 1; i >= head; i --) {
			ans += (expression[i] - '0') * pow(10, last - i - 1);
		}
		return ans;
	}
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
	int bracket = 0;
	scanf("%s", expression);
	len = strlen(expression);
	for(int i = 0; i < len - 1; i ++) {
		if(expression[i] == '(') bracket ++;
		if(expression[i] == ')') bracket --;
	}
	if(bracket != 0) {//括号不匹配 
		printf("NO\n");
		//printf("%d", bracket);
		return 0;
	}
	for(int i = 1; i < len - 1; i ++) {//符号有重复
		if(lev(expression[i]) != 0 && lev(expression[i - 1]) != 0) {
            printf("NO\n");
			return 0;
        }
	}
	if(len == 2 && lev(expression[0]) != 0 || !(expression[len - 2] >= '0' && expression[len - 2] <= '9'))//算式不合法 
    {
        printf("NO\n");
        return 0;
    }
	for(int i = 0; i < len - 1; i ++) {
		if(expression[i] <= '9' && expression[i] >= '0' || (i == 0 && expression[i] == '-') || (expression[i - 1] == '(' && expression[i] == '-')) {
			a.push(read(i));
			//printf("%d\n",read(i));
			if((i == 0 && expression[i] == '-') || (expression[i - 1] == '(' && expression[i] == '-')) i ++;
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
