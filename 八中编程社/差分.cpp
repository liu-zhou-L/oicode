#include<cstdio>
int a[100005]={},f[100005]={},n,m;
void read(int &l) {
	bool w=0;
	char ch=0;
    while(ch<'0'||ch>'9') {
    	if(ch=='-') w=1;
		ch=getchar();
	}
    while(ch>='0'&&ch<='9') {
    	l*=10;
    	l+=ch-48;
    	ch=getchar();
	}
    if(w==1) l=-l;
}
void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main() {
	int l,r,c;
	/*read(n);
	read(m);*/scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		//read(a[i]);
		scanf("%d",&a[i]);
		f[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=m;i++) {
		//read(l);
		//read(r);
		//read(c);
		scanf("%d%d%d",&l,&r,&c);
		f[l]+=c;
		f[r+1]-=c;
	}
	for(int i=1;i<=n;i++) {
		f[i]+=f[i-1];
	}
	for(int i=1;i<=n;i++) {
		//write(f[i]);
		printf("%d ",f[i]);
	}
	return 0;
}
