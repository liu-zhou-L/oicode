#include <cstdio>

long long xia, shang, ans = 0;

bool check_zhishu(long long x) {
	for (long long i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
} 

int main() {
	//scanf("%lld %lld", &xia, &shang);
	freopen("1e8以内质数.txt", "w", stdout);
	for (long long i = 2; i <= 1e8; i++) {
		if(check_zhishu(i)) {
			printf("%lld ", i); 
			ans++;
		}
	}
	printf("\n%lld", ans);
	return 0;
}
