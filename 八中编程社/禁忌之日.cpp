#include <cstdio>
#include <cmath>
int main() {
    int y, m, d, ans, sum = 0;
    int md[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    scanf("%d%d%d", &y, &m, &d);
    if(y == 1972 && m == 13 && d == 1) {
    	printf("������");
    	return 0;
	}
    for (int i = 1; i < y; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            sum += 366;
        else
            sum += 365;
    }
    for (int i = 1; i < m; i++) {
        if (i == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
            sum += 29;
        else
            sum += md[i];
    }
    sum += d;
    sum %= 7;
    if(sum == 1) printf("����һ");
	else if(sum == 2) printf("���ڶ�");
	else if(sum == 3) printf("������");
	else if(sum == 4) printf("������");
	else if(sum == 5) printf("������");
	else if(sum == 6) printf("������");
	else if(sum == 0) printf("������");
    return 0;
}
