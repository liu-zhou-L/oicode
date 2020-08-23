#include<cstdio>
int a[105][105];
int main()
{
	int n,sum,cnt;
	int h=99999999,l=99999999,d;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
		for(int j=1;j<=n;j+=1)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i+=1)
	{
		sum=0;
		cnt=0;
		for(int j=1;j<=n;j+=1)
		{
			sum+=a[i][j];
			cnt+=a[j][i];
		}
		if(h>sum)h=sum;
		if(l>cnt)l=cnt;
	}
	sum=0;
	cnt=0;
	for(int i=1;i<=n;i+=1)
	{
		sum+=a[i][i];
		cnt+=a[i][n+1-i];
	}
	if(sum<cnt) d=sum;
	else d=cnt;
	if(h<=l&&h<=d)printf("%d\nROW",h);
	else if(h>l&&l<=d)printf("%d\nCOL",l);
	else if(d<h&&d<l)printf("%d\nDIA",d);
}
