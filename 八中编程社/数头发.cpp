#include <cstdio>
#include <cmath>

#define LL long long

LL m, a, c, x_0, n, g;

LL q_mul(LL x, LL y) {//���ٳ�x*y 
	LL ans = 0;
	while(y) {//������Ϊ��ʱ 
		if(y & 1) ans = (ans + x) % m;//��ǰ������λ������ʱ����x�ӵ�ans�� 
		x = (x + x) % m;
		y >>= 1; 
	}
	return ans % m;
}

LL q_pow(LL x, LL y) {//������ x^y
	LL ans = 1;
	while(y) {//ָ����Ϊ��ʱ 
		if(y & 1) ans = q_mul(ans, x);//��ǰ������λ������ʱ����x�˵�ans�� 
		x = q_mul(x, x);
		y >>= 1;//��ͬ�ڳ�2��ģ������� 
	}
	return ans % m;
}

LL hair(LL x, LL y) {//�ռ����������� 
	if(y == 0) return 1;//x^0=1
	if(y == 1) return (x + 1) % m;//x^1 + x^0 = x + 1
	if(y & 1) return q_mul((q_pow(x, (y >> 1) + 1) % m + 1) % m, hair(x, y >> 1) % m) % m;//yΪ����ʱ��x^y + x^(y - 1) + ... + x^0�͵���x^(y / 2 + 1) * [(x^(y / 2) + x^(y / 2 - 1) + ... + x^0)]
	return q_mul((q_pow(x, y >> 1) + 1) % m, hair(x, (y >> 1) - 1) % m) % m + q_pow(x, y) % m;//yΪż��ʱ��x^y + x^(y - 1) + ... + x^0�͵���x^(y / 2 + 1) * [(x^(y / 2 - 1) + x^(y / 2 - 1) + ... + x^0)] + x^y
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
} // ���ģ�岻�ù�

typedef long long LL;
LL MOD, a, c, X0, n, g;

LL fast_mul(LL x, LL y) {
	LL res = 0;
	for (; y; y >>= 1, x = (x + x) % MOD)
		if (y & 1) res = (res + x) % MOD;
	return res % MOD;
} // ���ٳ˷�

LL fast_pow(LL x, LL y) {
	LL res = 1;
	for (; y; y >>= 1, x = fast_mul(x, x))
		if (y & 1) res = fast_mul(res, x);
	return res % MOD;
} // ��������

// ������������������ģ�壬�����ûѧ�����ݵĻ��Ƽ�ѧһ�£������ݶ��˿��ٳ˾�����Ȼ��Ȼ��
// �Ƽ�����ƪhttps://oi-wiki.org/math/quick-pow/

LL get_sum(LL x, LL y) {
	if (y == 0) return 1; // �߽�
	else if (y == 1) return (x + 1) % MOD; // �߽�
	// �߽����������ʽ���Ѿ��������
	else if (y & 1) return fast_mul((fast_pow(x, (y >> 1) + 1) % MOD + 1) % MOD, get_sum(x, y >> 1) % MOD) % MOD;
	// �����ߴ�Ϊ�������Ͱ������ʽ����
	else return fast_mul((fast_pow(x, y >> 1) + 1) % MOD, get_sum(x, (y >> 1) - 1) % MOD) % MOD + fast_pow(x, y) % MOD;
	// �����ߴ�Ϊż�����Ͱ���ߴε�������������ݣ��ٺ�ʣ�ಿ�ּ�����
}

signed main() {
	read(MOD, a, c, X0, n, g);
	X0 %= MOD;
	printf("%lld\n", (fast_mul(fast_pow(a, n) % MOD, X0) % MOD + fast_mul(get_sum(a, n - 1) % MOD, c % MOD) % MOD) % MOD % g);
	// ����������ǵĴ�
	// ��ʵ�������붼����ڹ�������ʽ��
	// ������뿴�����Ƽ����ʽ��һ�𿴾ͺܺö���
	return 0;
}*/
