#include<cstdio>
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i+=1) {
    	if(i%3==0) sum+=i;
    }
    printf("%d",sum);
    return 0;
}
