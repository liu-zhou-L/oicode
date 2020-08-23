#include <cstdio>

const int MAXN = 1e6;

int n, k, x[MAXN + 5], pre[MAXN + 5], head = 0, end = 1;
bool flag[MAXN + 5];

void print(int x) {
    int ans = 0;
    while (pre[x]) {
        ans++;
        x = pre[x];
    }
    printf("%d", ans);
    return;
}

int main() {
    scanf("%d%d", &n, &k);
    if (n == k) {
        printf("0");
        return 0;
    }
    x[1] = n;
    flag[n] = true;
    while (1) {
        head++;
        int next;
        for (int i = 1; i <= 3; i++) {
            switch (i) {
                case 1:
                    next = x[head] + 1;
                    break;
                case 2:
                    next = x[head] - 1;
                    break;
                case 3:
                    next = x[head] * 2;
                    break;
            }
            if (next >= 0 && next <= MAXN && !flag[next]) {
                end++;
                x[end] = next;
                flag[next] = true;
                pre[end] = head;
                if (next == k) {
                    print(end);
                    return 0;
                }
            }
        }
    }
    return 0;
}
