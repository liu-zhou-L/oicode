#include <cstdio>
#include <cmath>

#define LL long long

LL m, a, c, x_0, n, g;

LL q_mul(LL x, LL y) {//快速乘x*y 
	LL ans = 0;
	while(y) {//因数不为零时 
		if(y & 1) ans = (ans + x) % m;//当前二进制位上有数时，将x加到ans中 
		x = (x + x) % m;
		y >>= 1; 
	}
	return ans % m;
}

LL q_pow(LL x, LL y) {//快速幂 x^y
	LL ans = 1;
	while(y) {//指数不为零时 
		if(y & 1) ans = q_mul(ans, x);//当前二进制位上有数时，将x乘到ans中 
		x = q_mul(x, x);
		y >>= 1;//等同于除2，模拟二进制 
	}
	return ans % m;
}

LL hair(LL x, LL y) {//终极函数！！！ 
	if(y == 0) return 1;//x^0=1
	if(y == 1) return (x + 1) % m;//x^1 + x^0 = x + 1
	if(y & 1) return q_mul((q_pow(x, (y >> 1) + 1) % m + 1) % m, hair(x, y >> 1) % m) % m;//y为奇数时，x^y + x^(y - 1) + ... + x^0就等于x^(y / 2 + 1) * [(x^(y / 2) + x^(y / 2 - 1) + ... + x^0)]
	return q_mul((q_pow(x, y >> 1) + 1) % m, hair(x, (y >> 1) - 1) % m) % m + q_pow(x, y) % m;//y为偶数时，x^y + x^(y - 1) + ... + x^0就等于x^(y / 2 + 1) * [(x^(y / 2 - 1) + x^(y / 2 - 1) + ... + x^0)] + x^y
}

int main() {
	scanf("%lld %lld %lld %lld %lld %lld", &m, &a, &c, &x_0, &n, &g);
	x_0 %= m;
	printf("%lld", (q_mul(q_pow(a, n) % m, x_0) % m + q_mul(hair(a, n - 1) % m, c % m) % m) % m % g);//
	return 0;
}
/*
#include <cstdio>

char buf[1 << 21], *p1 = buf, *p2 = buf;
#ifndef ONLINE_JUDGE
#define gc() getchar()
#else
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
#endif
#define is_number (ch >= '0' && ch <= '9')

template < typename Type >
void read(Type& a) {
	a = 0; bool f = 0; char ch;
	while (!(ch = gc(), is_number)) if (ch == '-') f = 1;
	while (is_number) a = (a << 3) + (a << 1) + (ch ^ '0'), ch = gc();
	a = (f ? -a : a);
}

template < typename Type, typename... Args >
void read(Type& t, Args&... args) {
	read(t), read(args...);
} // 快读模板不用管

typedef long long LL;
LL MOD, a, c, X0, n, g;

LL fast_mul(LL x, LL y) {
	LL res = 0;
	for (; y; y >>= 1, x = (x + x) % MOD)
		if (y & 1) res = (res + x) % MOD;
	return res % MOD;
} // 快速乘法

LL fast_pow(LL x, LL y) {
	LL res = 1;
	for (; y; y >>= 1, x = fast_mul(x, x))
		if (y & 1) res = fast_mul(res, x);
	return res % MOD;
} // 快速求幂

// 上面这两个基本都是模板，如果还没学快速幂的话推荐学一下，快速幂懂了快速乘就是自然而然了
// 推荐看这篇https://oi-wiki.org/math/quick-pow/

LL get_sum(LL x, LL y) {
	if (y == 0) return 1; // 边界
	else if (y == 1) return (x + 1) % MOD; // 边界
	// 边界问题上面的式子已经很清楚了
	else if (y & 1) return fast_mul((fast_pow(x, (y >> 1) + 1) % MOD + 1) % MOD, get_sum(x, y >> 1) % MOD) % MOD;
	// 如果最高次为奇数，就按上面的式子来
	else return fast_mul((fast_pow(x, y >> 1) + 1) % MOD, get_sum(x, (y >> 1) - 1) % MOD) % MOD + fast_pow(x, y) % MOD;
	// 如果最高次为偶数，就把最高次单独提出来快速幂，再和剩余部分加起来
}

signed main() {
	read(MOD, a, c, X0, n, g);
	X0 %= MOD;
	printf("%lld\n", (fast_mul(fast_pow(a, n) % MOD, X0) % MOD + fast_mul(get_sum(a, n - 1) % MOD, c % MOD) % MOD) % MOD % g);
	// 这个就是我们的答案
	// 其实整个代码都是在诠释上面的式子
	// 如果代码看不懂推荐结合式子一起看就很好懂了
	return 0;
}*/
