#include<cstdio>
int main() {
	int a;
	while(scanf("%d",&a)==1) {
		for(int i=1;i<=15;i++) {
			if(a&1&&a!=1||a==2) break;
			a>>=2;
		}
		if(a==1) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}
