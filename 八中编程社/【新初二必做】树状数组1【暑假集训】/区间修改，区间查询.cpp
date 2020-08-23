#include <bits/stdc++.h>
using namespace std;

//粘贴复制至头文件下即可
#pragma once 
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

namespace io {
char buf[1 << 21], *p1 = buf, *p2 = buf, buf1[1 << 21];
inline char gc() {
    if (p1 != p2)
        return *p1++;
    p1 = buf;
    p2 = p1 + fread(buf, 1, 1 << 21, stdin);
    return p1 == p2 ? EOF : *p1++;
}
#define G gc

#ifndef ONLINE_JUDGE
#undef G
#define G getchar
#endif

template <class I>
inline void read(I &x) {
    x = 0;
    I f = 1;
    char c = G();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = G();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = G();
    }
    x *= f;
}

template <class I>
inline void write(I x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    I tmp = x > 0 ? x : -x;
    if (x < 0)
        putchar('-');
    int cnt = 0;
    while (tmp > 0) {
        buf1[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while (cnt > 0) putchar(buf1[--cnt]);
}

#define in(x) read(x)
#define outn(x) write(x), putchar('\n')
#define out(x) write(x), putchar(' ')

}  // namespace io
using namespace io;

#define ll long long
const int N = 100010;

const int MAXN = 1e6 + 5;

int n, q, a[MAXN] = {};
ll Bit[MAXN] = {}, Bit_[MAXN] = {};

int lowbit(const int &x) { return x & -x; }

void updata(const int &num, const int &x) {
	for (int i = num; i <= n; i += lowbit(i)) {
		Bit[i] += x;
		Bit_[i] += (ll)(num - 1) * x;
	}
	return;
}

ll Sum(const int &x) {
	ll ret = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		ret += x * Bit[i];
		ret -= Bit_[i];
	}
	return ret;
}

ll qzh(const int &i, const int &j) {
	return Sum(j) - Sum(i - 1);
}

int main() {
	in(n);
	in(q);
	for (int i = 1; i <= n; i++) {
		//scanf("%d", &a[i]);
		in(a[i]);
		updata(i, a[i] - a[i - 1]);
	}
	for (int i = 1; i <= q; i++) {
		int cmd, l, r, x;
		//scanf("%d%d%d", &cmd, &l, &r);
		in(cmd);
		in(l);
		in(r);
		if (cmd == 1) {
			//scanf("%d", &x);
			in(x);
			updata(l, x);
			updata(r + 1, -x);
		} else {
			//printf("%lld\n", qzh(l, r));	
			outn(qzh(l, r));
		}
	}
	return 0;
} 
