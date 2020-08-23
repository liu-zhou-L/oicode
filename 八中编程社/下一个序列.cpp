//ÒÑÍê³É 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int len;
char a[90];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %s", &i, a);
		len = strlen(a);
		printf("%d ", i);
		bool flag = 0;
		int index;
		for(index = len - 2; index >= 0; index --) {
			if(a[index] < a[index + 1]) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) {
			for(int j = len - 1; j >= index; j --) {
				if(a[j] > a[index]) {
				 	swap(a[j], a[index]);
				 	sort(a + index + 1, a + len);
				 	break;
				}
			}
			for(int j = 0; j < len; j ++) {
				printf("%c", a[j]);
			}
			printf("\n");
		}
		else {
			printf("BIGGEST\n");
		}
	}
	return 0;
}

