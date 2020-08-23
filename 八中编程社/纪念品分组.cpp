#include<cstdio>
#include<algorithm>
using namespace std;
int a[30005];
int main() {
    int n, c, sum = 0;
    scanf("%d%d", &c, &n);
    int i = 1, j = n;
    for(int i = 1; i <= n; i += 1) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    while(i <= j){
        if(a[j] >c) {
            j --;
        }
        else if(a[j] + a[i] > c) {
            sum ++;
            j --;
        }
        else if(a[j] + a[i] <= c) {
            sum ++;
            i ++;
            j --;
        }
    }
    printf("%d", sum);
    return 0;
}
