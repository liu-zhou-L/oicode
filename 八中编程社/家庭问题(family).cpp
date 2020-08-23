#include <cstdio>//���鼯 

const int MAXN = 105;

struct member {
	int source, sum;//source��ʾ��ǰ������������ϴ� ,sum��ʾ����˼����µ�����
	member() {
		sum = 1;
	}
} family[MAXN]; 

int sources(int f) { // �Ҽ����ϴ� 
	if(family[f].source == f) {
		return f;
	}
	else {
		return family[f].source = sources(family[f].source);
	}
}

void merge(int f, int s) { //�ϲ��������� 
	int s1, s2;
	s1 = sources(family[f].source);
	s2 = sources(family[s].source);
	if(s1 != s2) {
		family[s].source = s1;
		family[s1].sum += family[s2].sum;
	}
	return;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++) {
		family[i].source = i;
	}
	int x, y;
	for(int i = 1; i <= k; i ++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	int sum = 0, max = -1;
	for(int i = 1; i <= n; i ++) {
		if(family[i].source == i) {
			sum ++;
			if(family[i].sum > max) {
				max = family[i].sum;
			}
		} 
	}
	printf("%d %d", sum, max);
	return 0;
}

