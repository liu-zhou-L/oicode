#include<cstdio>
#include<algorithm>
using namespace std;
int a[105][105],b[105][105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
		for(int j=1;j<=i;j+=1)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i+=1)
		b[n][i]=a[n][i];
	for(int i=n-1;i>=1;i-=1)
		for(int j=1;j<=i;j+=1)
		{
			b[i][j]=a[i][j]+max(b[i+1][j],b[i+1][j+1]);
		}
	printf("%d",b[1][1]);
}
