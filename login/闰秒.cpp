#include<cstdio>
int main()
{
	int n,h,m,s;
	scanf("%d",&n);
	s=n%61;
	m=n/61%60;
	h=n/3660;
	if(h<10) printf("0");
	printf("%d:",h);
	if(m<10) printf("0");
	printf("%d:",m);
	if(s<10) printf("0");
	printf("%d",s);
}
