#include<cstdio>
int main()
{
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            int t=100-i-j;
            if(t<0||t%3!=0) continue;
            if(t/3+i*5+j*3==100)
            {
                printf("%d %d %d\n",i,j,t);
            } 
        }
 
    }
    return 0;
 } 
