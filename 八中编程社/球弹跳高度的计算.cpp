#include<cstdio>
int main()
{
    double h,sum=0;
    scanf("%lf",&h);
    sum+=h;
    for(int i=1;i<10;i+=1) {
		h/=2;
    	sum+=h*2;
	}
	h/=2;
	printf("%g\n%g",sum,h);
    return 0;
 } 
