#include<cstdio>
int main()
{
    int n,a=0;
    scanf("%d",&n);
    for(int i=1;i<n;i+=1) a+=i;
    printf("%d",a*2+n-1);
    return 0;
}
