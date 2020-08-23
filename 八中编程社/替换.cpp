//×îºó±à¼­20/3/3
#include <cstdio>

long long n, l, r;

int dg(long long x, long long left, long long right) {
	if(r < left || l > right || x == 0) {
        return 0;		
	}
    if(x == 1) {
        return 1;    	
	}
    long long mid = (left + right) / 2;
    return dg(x / 2, left, mid - 1) + dg(x % 2, mid, mid) + dg(x / 2, mid + 1, right);
}

int main() {
	scanf("%lld %lld %lld", &n, &l, &r);
	long long len = 1;
	for(long long i = n >> 1; i >= 1 ; i >>= 1) {
		len = len * 2 + 1;
	}
	//printf("%lld", len);
	printf("%d", dg(n, 1, len));
	return 0;
}

