#include<cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i+=1)
    {
        for(int j=1;j<=i;j+=1)
        {
            printf("%d*%d=%d ",j,i,i*j);
        }
        printf("\n");
    }
}
