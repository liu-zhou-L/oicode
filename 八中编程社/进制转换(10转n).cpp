#include<cstdio>
#include<cmath>
int main() {
	int num, sum = 1, n;
	scanf("%d%d", &num, &n);
	for(int i = 0;;i ++) {
		if(sum <= num && sum * n > num) break;
		sum *= n;
	}
	while(num) {
		printf("%d", num / sum);
		num %= sum;
		sum /= n;
	}
	while(sum >= 1) {
		printf("0");
		sum /= n;
	}
	return 0;
}

