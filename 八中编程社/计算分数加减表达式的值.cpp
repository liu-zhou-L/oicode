#include<cstdio>
int main()
{
    double sum=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i+=1) {
    	if(i%2==1) sum+=1.0/i;
    	else sum-=1.0/i;
    }
    printf("%.4lf",sum);
    return 0;
}
