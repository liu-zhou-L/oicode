#include<cstdio>
int n;
int main() {
	int a=0,b=1,c=0;
	scanf("%d",&n);
	while(c<n) {
		c=a+b;
		b=a;
		a=c;
	}
	if(c==n) printf("YES");
	else printf("NO");
	return 0;
}

