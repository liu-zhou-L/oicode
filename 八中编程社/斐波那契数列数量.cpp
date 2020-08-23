#include<cstdio>
bool f(int n) {
	int a=0,b=1,c=0;
	while(c<n) {
		c=a+b;
		b=a;
		a=c;
	}
	if(c==n) return 1;
	else return 0;
}
int main() {
	int a,b,sum=0;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++) {
		if(f(i)) sum++;
	}
	printf("%d",sum);
	return 0;
}

