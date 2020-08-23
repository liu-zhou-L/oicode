#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2005;

struct node {
    int x, y, a;
    bool vis;
    bool operator<(const node& that) const { return this->a < that.a; }
    bool operator<=(const node& that) const { return this->a <= that.a; }
} heap[100 * MAXN];

int size = 0;

void Put(node num) {
    int x = ++size;
    heap[size] = num;
    while (x > 1) {
        if (heap[x] < heap[x >> 1]) {
            swap(heap[x], heap[x >> 1]);
            x >>= 1;
        } else
            break;
    }
    return;
}

void Pop() {
    heap[1] = heap[size--];
    int x = 1;
    while (x <= (size >> 1)) {
        int son = x * 2;
        if (son < size && heap[son + 1] < heap[son])
            son++;
        if (heap[x] <= heap[son])
            break;
        swap(heap[x], heap[son]);
        x = son;
    }
    return;
}

int t, m, n, one[MAXN], two[MAXN], p[MAXN];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &one[i]);
        }
        sort(one + 1, one + 1 + n);
        for (int i = 1; i <= m - 1; i++) {
            size = 0;
            for (int j = 1; j <= n; j++) {
                scanf("%d", &two[j]);
            }
            sort(two + 1, two + 1 + n);
            /*printf("one:");
            for (int j = 1; j <= n; j++) {
                    printf("%d ", one[j]);
            }
            puts("");
            printf("two:");
            for (int j = 1; j <= n; j++) {
                    printf("%d ", two[j]);
            }
            puts("");*/
            node temp;
            temp.a = one[1] + two[1];
            temp.vis = false;
            temp.x = 1;
            temp.y = 1;
            Put(temp);
            for (int j = 1; j <= n; j++) {
                node t = heap[1];
                p[j] = heap[1].a;
                // printf("p[%d] = %d\n", j, p[j]);
                Pop();
                if (!temp.vis) {
                    temp = t;
                    ++temp.y;
                    temp.a = one[temp.x] + two[temp.y];
                    temp.vis = false;
                    Put(temp);
                    // printf("PUT = %d = one[%d](=%d) + two[%d](=%d)\n", temp.a, temp.x, one[temp.x], temp.y,
                    // two[temp.y]);
                    temp = t;
                    ++temp.x;
                    temp.a = one[temp.x] + two[temp.y];
                    temp.vis = true;
                    Put(temp);
                    // printf("PUT = %d = one[%d](=%d) + two[%d](=%d)\n", temp.a, temp.x, one[temp.x], temp.y,
                    // two[temp.y]);
                } else {
                    temp = t;
                    ++temp.x;
                    temp.a = one[temp.x] + two[temp.y];
                    temp.vis = true;
                    Put(temp);
                    // printf("PUT = %d = one[%d](=%d) + two[%d](=%d)\n", temp.a, temp.x, one[temp.x], temp.y,
                    // two[temp.y]);
                }
            }
            for (int j = 1; j <= n; j++) {
                // printf("%d ", p[j]);
                one[j] = p[j];
            }
            // puts("");
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", one[i]);
        }
        puts("");
    }
    return 0;
}
