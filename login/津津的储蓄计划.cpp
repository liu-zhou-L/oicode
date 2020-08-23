#include<cstdio>
int main()
{
	int cun=0,yong=0,sheng=0,num=0,flag=0;
	for(int i=1;i<=12;i+=1)
	{
		scanf("%d",&yong);
		if(yong<300+sheng&&(yong+sheng)/100>0)
		{
			cun+=(yong+sheng)/100;
			sheng+=yong-yong/100;
		}
		else if(sheng+300<yong)
		{
			flag=i;
			break;
		}
	}
	if(flag==0)
	{
		printf("%d",sheng+cun*1.2);
	}
	else
	{
		printf("-%d",flag);
	}
}
