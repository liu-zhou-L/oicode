#include<cstdio>
int main() {
	int a;
	scanf("%d",&a);
	if(a>0) printf("+");
	else if(a<0) printf("-");
	else printf("0");
	return 0;
}
