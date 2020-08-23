#include<cstdio>
int main()
{
	int a[3][3],max=-10000000,min=10000000,maxx,maxy,minx,miny;
	for(int x=0;x<=2;x+=1)
	{
		for(int y=0;y<=2;y+=1)
		{
			scanf("%d",&a[x][y]);
		} 
	}
	for(int x=0;x<=2;x+=1)
	{
		for(int y=0;y<=2;y+=1)
		{
			if(a[x][y]>max)
			{
				max=a[x][y];
				maxx=x;
				maxy=y;
			} 
			if(a[x][y]<min)
			{
				min=a[x][y];
				minx=x;
				miny=y;
			} 
		} 
	}
	printf("max=%d (%d,%d)\nmin=%d (%d,%d) ",max,maxx+1,maxy+1,min,minx+1,miny+1);
} 
