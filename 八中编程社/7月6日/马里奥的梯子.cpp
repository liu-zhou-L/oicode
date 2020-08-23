#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 55;

struct node {
    int r;
    int c;
};

int x, y, n, m;
bool flag[MAXN][MAXN], a[MAXN][MAXN];
queue<node> que;

bool check(int cd) {
    while (!que.empty()) que.pop();
    node t;
    memset(flag, false, sizeof(flag));
    flag[x][y] = true;
    t.r = x;
    t.c = y;
    que.push(t);
    while (!que.empty()) {
        for (int i = 1; i <= 4; i++) {
            node temp = que.front();
            if (i == 1) {
                temp.c++;
                if (a[temp.r][temp.c] && !flag[temp.r][temp.c]) {
                    flag[temp.r][temp.c] = true;
                    que.push(temp);
                }
            } else if (i == 2) {
                temp.c--;
                if (a[temp.r][temp.c] && !flag[temp.r][temp.c]) {
                    flag[temp.r][temp.c] = true;
                    que.push(temp);
                }
            } else if (i == 3) {
                for (int j = 1; j <= cd; j++) {
                    if (!flag[temp.r + j][temp.c] && a[temp.r + j][temp.c]) {
                        temp.r += j;
                        if (temp.r == n)
                            return true;
                        flag[temp.r][temp.c] = true;
                        que.push(temp);
                        break;
                    }
                }
            } else {
                for (int j = 1; j <= cd; j++) {
                    if (temp.r - j >= 1 && !flag[temp.r - j][temp.c] && a[temp.r - j][temp.c]) {
                        temp.r -= j;
                        flag[temp.r][temp.c] = true;
                        que.push(temp);
                        break;
                    }
                }
            }
        }
        que.pop();
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= m; j++) {
            char temp;
            scanf("%c", &temp);
            if (temp == '.')
                a[i][j] = false;
            else
                a[i][j] = true;
        }
    }
    scanf("%d%d", &x, &y);
    if (x == n) {
        printf("0");
        return 0;
    }
    int left = 1, right = n - x, ans;
    while (right >= left) {
        int mid = (right + left) >> 1;
        if (check(mid) && !check(mid - 1)) {
            ans = mid;
            break;
        } else if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}
/*7 7
###....
.......
#.#....
.......
#......
.......
#......
3 3*/
