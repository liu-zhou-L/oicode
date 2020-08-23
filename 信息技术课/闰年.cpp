#include<cstdio>
int main() {
	int n;
	scanf("%d",&n);
	if((n%4==0&&n%100!=0)&&(n%400==0&&n%3200!=0)) printf("TRUE");
	else printf("FALSE");
	return 0;
}
