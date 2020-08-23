#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    queue<int> ms, ns;
    int a = 1;
    if (n == 0) return 0;
    printf("1\n");
    for (int i = 1; i < n; i++) {
        ms.push(a * 2 + 1);
        ns.push(a * 3 + 1);
        if (ms.front() < ns.front()) {
            a = ms.front();
            ms.pop();
        } else if (ms.front() > ns.front()) {
            a = ns.front();
            ns.pop();
        } else {
            a = ms.front();
            ms.pop();
            ns.pop();
        }
        printf("%d\n", a);
    }
    return 0;
}
