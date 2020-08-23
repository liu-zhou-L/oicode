#include <cstdio>
#include<climits>

const int MAXN = 505;

int left = 0, right = 0, books[MAXN], m, k;

bool check(int x) {
	int tot = 0, sum = 1;
	for(int i = 1; i <= m; i ++) {
		if(books[i] > x) return false;//一本就超了，直接返回假 
		if(tot + books[i] <= x) tot += books[i];
		else {//如果超过了，增加一个人 
			tot = books[i];//当前这一本给下一个人 
			sum ++;
		}
	}
	return sum <= k;
}

void f() {
	int mid;
	while(left + 1 < right) {//左闭右开 
		mid = (left + right) / 2;//mid为所有人抄的页数均不超过mid，且满足题意的值 
		if(check(mid) == 1) {//二分查找mid 
			right = mid;
		}
		else {
			left = mid;
		}
	}
	//right为合适的页数
	//printf("%d", right);
	int tot = 0, st = m, head[MAXN], last[MAXN], index = 0;
	books[0] = INT_MAX / 2;
	for(int i = m; i >= 0; i --) {
		if(tot + books[i] <= right) {//让前面的人少，所以倒着来 
			tot += books[i];
		}
		else {
			index ++;
            head[index] = i + 1;
            last[index] = st;
            st = i;
            tot = books[i];
		}
	}
	for(int i = k; i >= 1; i --) {
		printf("%d %d\n", head[i], last[i]);
	}
}

int main() {
	scanf("%d %d", &m, &k);
	for(int i = 1; i <= m; i ++) {
		scanf("%d", &books[i]);
		right += books[i];
	}
	f();
	return 0;
}
