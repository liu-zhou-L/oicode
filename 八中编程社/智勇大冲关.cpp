#include<cstdio>
int main() {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a>=60&&b>=60&&c>=60)	printf("first prize");
	else if(a>=60&&b>=60) printf("second prize");
	else if(a>=60) printf("third prize");
	else printf("consolation prize");
	return 0;
}
