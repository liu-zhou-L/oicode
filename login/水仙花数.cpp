#include<cstdio>
int main ()
{
    int a,b;
    scanf("%d",&a);
    for(b=100;b<=a;b+=1)
    {
        if(b==(b%10)*(b%10)*(b%10)+(b/10%10)*(b/10%10)*(b/10%10)+(b/100)*(b/100)*(b/100))
        {
            printf("%d\n",b);
        }
    }
}

