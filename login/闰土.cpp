#include<cstdio>
int main()
{
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    a=f-c+(e-b)*60+(d-a)*3600;
    printf("%d",a);
    return 0;
} 
