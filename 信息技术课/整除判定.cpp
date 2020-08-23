#include<cstdio>
int main() {
	int a,b;
	scanf("%d %d",&a,&b);
	if(a%b==0||b%a==0) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}
