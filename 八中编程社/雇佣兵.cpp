#include<cstdio>
#include<cmath>
int main()
{
	int m,n,x;
	scanf("%d%d%d",&m,&n,&x);
	while(1) { 
		x-=ceil(1.0*m/n);
		if(x<0) break;
		n+=m/n;
	}
	printf("%d",n);
	return 0;
}
