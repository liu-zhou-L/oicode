#include <cstdio>
#include <cmath>

int m, n, ans = 0;

bool check(int x) {
    int sum = 0, y = x;
    while (y) {
        sum += pow(y % 10, 3);
        y /= 10;
    }
    if (x == sum) {
        printf("%d ", x);
        return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++) {
        if (check(i))
            ans++;
    }
    if (ans)
        printf("\n%d", ans);
    else
        printf("No Answer.");
    return 0;
}
