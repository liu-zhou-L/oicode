#include<cstdio>
int main()
{
    long long n,a=1;
    scanf("%lld",&n);
    for(long long i=2;i<=n;i+=1) {
    	a*=i;
    }
    printf("%lld",a);
    return 0;
}
