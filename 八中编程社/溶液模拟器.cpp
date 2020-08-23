//×îºó±à¼­
#include <cstdio>
#include <stack>
using namespace std;

const int MAXN = 1e4 + 5;

stack<int> v;
stack<double> c;
int vs, n;
double cs;
char signs;

int main() {
	scanf("%d %lf %d", &vs, &cs, &n);
	v.push(vs);
	c.push(cs);
	while(n--) {
		scanf("\n%c", &signs);
		if(signs == 'P') {
			scanf("%d %lf", &vs, &cs);
			cs = (c.top() * v.top() + vs * cs) / (v.top() + vs);
			vs += v.top();
			v.push(vs);
			c.push(cs);
		}
		else if(signs == 'Z') {
			if(v.size() > 1) {
				v.pop();
				c.pop();
			}
		}
		//getchar();
		printf("%d %.5lf\n", v.top(), c.top());
	}
	return 0;
}

