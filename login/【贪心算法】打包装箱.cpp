#include<cstdio>
int room[4]={0,5,3,1};
int main()
{
	int s1,s2,s3,s4,s5,s6,sum=0,n2,n1;
	scanf("%d%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5,&s6);
	sum+=s6+s5+s4+(s3+3)/4;
	n2=s4*5+room[s3%4];
	if(s2>n2)
	{
		sum+=(s2-n2+8)/9;
	}
	n1=36*sum-s2*2*2-s3*3*3-s4*4*4-s5*5*5-s6*6*6;
	if(s1>n1)
	{
		sum+=(s1-n1+35)/36;
	}
	printf("%d",sum);
 } 
