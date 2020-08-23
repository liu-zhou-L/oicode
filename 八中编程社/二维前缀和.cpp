#include<cstdio>
#include<cctype>
long long a[1005][1005],b,n,m,q,x1,y1,x2,y2;
long long read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
void write(long long x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
int main() {
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			//scanf("%lld",&b);
			b=read();
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+b;
		}
	}
	for(int i=1;i<=q;i++) {
		//scanf("%lld%lld%lld%lld",&y1,&x1,&y2,&x2);
		y1=read();
		x1=read();
		y2=read();
		x2=read();
		//printf("%lld\n",a[y2][x2]-a[y2][x1-1]-a[y1-1][x2]+a[y1-1][x1-1]);
		write(a[y2][x2]-a[y2][x1-1]-a[y1-1][x2]+a[y1-1][x1-1]);
		puts("");
	}
	return 0;
} 
