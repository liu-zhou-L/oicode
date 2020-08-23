// 2020/02/09
// C++
#include<cstdio>
#include<cstring>

int len;
char str[10], r[10];
bool flag[10];

void f(int index) {
    if(index > len) {
        for(int i = 1; i <= len; i ++) {
            printf("%c", r[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= len; i ++) {
        if(flag[i] == 0) {
        	flag[i] = 1;
            r[index] = str[i - 1];
            f(index + 1);
            flag[i] = 0;
        }
    }
}

int main() {
    scanf("%s", str);
    len = strlen(str);
    f(1);
    return 0;
}
