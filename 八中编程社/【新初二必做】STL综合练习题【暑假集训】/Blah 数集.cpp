#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int a, n;
    scanf("%d %d", &a, &n);
    queue<int> ms, ns;
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
    }
    printf("%d", a);
    return 0;
}
