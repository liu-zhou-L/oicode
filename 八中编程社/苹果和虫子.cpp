#include<cstdio>
int main() {
	double n,x,y;
	scanf("%lf%lf%lf",&n,&x,&y);
	n-=y/x;
	if(n<0) n=0; 
	printf("%d",int(n));
	return 0;
}
