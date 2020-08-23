#include<cstdio>
int main() {
	int a;
	while(scanf("%d",&a)==1) {
		if(a&(a-1)) printf("N\n");
		else printf("Y\n");
	}
	return 0;
}
