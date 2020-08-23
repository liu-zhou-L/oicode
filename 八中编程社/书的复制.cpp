#include <cstdio>
#include<climits>

const int MAXN = 505;

int left = 0, right = 0, books[MAXN], m, k;

bool check(int x) {
	int tot = 0, sum = 1;
	for(int i = 1; i <= m; i ++) {
		if(books[i] > x) return false;//һ���ͳ��ˣ�ֱ�ӷ��ؼ� 
		if(tot + books[i] <= x) tot += books[i];
		else {//��������ˣ�����һ���� 
			tot = books[i];//��ǰ��һ������һ���� 
			sum ++;
		}
	}
	return sum <= k;
}

void f() {
	int mid;
	while(left + 1 < right) {//����ҿ� 
		mid = (left + right) / 2;//midΪ�����˳���ҳ����������mid�������������ֵ 
		if(check(mid) == 1) {//���ֲ���mid 
			right = mid;
		}
		else {
			left = mid;
		}
	}
	//rightΪ���ʵ�ҳ��
	//printf("%d", right);
	int tot = 0, st = m, head[MAXN], last[MAXN], index = 0;
	books[0] = INT_MAX / 2;
	for(int i = m; i >= 0; i --) {
		if(tot + books[i] <= right) {//��ǰ������٣����Ե����� 
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
