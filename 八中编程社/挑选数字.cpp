#include<cstdio>//��߷�
#include<cstring>
const int MAXN = 100005;
int a[MAXN];
int main() {
	int N, n, s, max;
	scanf("%d", &N);
	while(N --) {
		max = 0;
		int l = MAXN;
		//memset(a,0,sizeof(a));
		scanf("%d %d", &n, &s);
		int right = 1, left = 1;
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			max += a[i];
		}
		if(max < s) {
			printf("0\n");
			continue;
		}
		if(max == s) {
			printf("%d\n", n);
			continue;
		}
		/*while(left <= n) {
			l -= a[left ++];
			ans -- ;
			if(l < s) {
				l += a[right + 1];
				right ++;
				ans ++;
			}
			if(l + a[right + 1] > s && right < left) {
				
			}
		}*/
		max = 0;
		while(1)
		{
			while(max < s && right <= n)   //ֱ���Ҷ˵��ٴ�ʹ����֮�ʹ���S
			{
				max += a[right];
				right ++;
			}
			if(max < s)
				break;
			if((right - left) < l) {
				l = right - left;
			}
			max -= a[left];       //��˵�����һ��
			left ++;
		}
		printf("%d\n",l);
	}
	return 0;
}

