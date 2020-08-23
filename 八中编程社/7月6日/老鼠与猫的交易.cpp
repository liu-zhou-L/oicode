#include <cstdio>
#include <algorithm>
using namespace std;

struct stu {
    double f, j, a;
} ni[10005];

bool cmp(stu x, stu y) { return x.a > y.a; }

int main() {
    int m, n;
    double sum = 0;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &ni[i].j, &ni[i].f);
        ni[i].a = ni[i].j / ni[i].f;
    }
    sort(ni + 1, ni + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        if (m >= ni[i].f) {
            m -= ni[i].f;
            sum += ni[i].j;
        }
		else {
            sum += ni[i].a * m;
            break;
        }
    }
    printf("%.3lf", sum);
    return 0;
}
