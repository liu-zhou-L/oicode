#include<cstdio>
#include<cmath>
int main() {
	int num, sum = 1;
	scanf("%d", &num);
	for(int i = 0;;i ++) {
		if(sum <= num && sum * 8 > num) break;
		sum *= 8;
	}
	while(num) {
		printf("%d", num / sum);
		num %= sum;
		sum /= 8;
	}
	while(sum >= 1) {
		printf("0");
		sum /= 8;
	}
	return 0;
}

