#include <cstdio>
int main() {
	int cnt_h = 0, cnt_q = 0, cnt_m = 0;
	char h, m, q;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("\n%c %c %c", &m, &q, &h);
		//һӮ��������
		//С��Ӯ��������� 
		if((h=='S' && q=='J' && m=='J') || (h=='J' && q=='B' && m=='B') || (h=='B' && q=='S' && m=='S')) {
			cnt_h += 2;
			cnt_q--;
			cnt_m--;
		} 
		//СǿӮ��������� 
		if((q=='S' && h=='J' && m=='J') || (q=='J' && h=='B' && m=='B') || (q=='B' && h=='S' && m=='S')) {
			cnt_q += 2;
			cnt_h--;
			cnt_m--;
		}
		//С��Ӯ��������� 
		if((m=='S' && q=='J' && h=='J') || (m=='J' && q=='B' && h=='B') || (m=='B' && q=='S' && h=='S')) {
			cnt_m += 2;
			cnt_q--;
			cnt_h--;
		}
		//��Ӯ�����
		//С���� 
		if((h=='S' && q=='S' && m=='J') || (h=='J' && q=='J' && m=='B') || (h=='B' && q=='B' && m=='S')) {
			cnt_m -= 2;
			cnt_q++;
			cnt_h++;
		}
		//Сǿ�� 
		if((h=='S' && q=='J' && m=='S') || (h=='J' && q=='B' && m=='J') || (h=='B' && q=='S' && m=='B')) {
			cnt_q -= 2;
			cnt_h++;
			cnt_m++;
		}
		//С���� 
		if((h=='S' && q=='B' && m=='B') || (h=='J' && q=='S' && m=='S') || (h=='B' && q=='J' && m=='J')) {
			cnt_h -= 2;
			cnt_m++;
			cnt_q++;
		}
	}
	printf("%d %d %d", cnt_m, cnt_q, cnt_h);
	return 0;
} 
