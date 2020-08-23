#include<cstdio>
int main()
{
    int n,a,max=-99999999;
    scanf("%d",&n);
    for(int i=1;i<=n;i+=1) {
    	scanf("%d",&a);
    	if(a>max) max=a;
    }
    printf("%d",max);
    return 0;
}
