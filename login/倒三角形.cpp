#include<cstdio>
int main()
{
    int a,b,c,d;
    scanf("%d",&a);
    if(a>20)
    {
    	printf("no answer");
	}
	else
	{
		d=(a-1)*2+1;
    	for(int i=(a-1)*2+1;i>0;i-=2)
    	{
    	    c=(d-i)/2;
    	   b=i;
     	   for(;c>0;c-=1)
     	   {
     	      printf(" ");
     	   }
     	   for(;b>0;b-=1)
     	   {
     	       printf("#");
     	   }
     	   printf("\n");
    	}
	}
}
