#include<cstdio>
int main() {
	int ans=0,n,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) {
		scanf("%d",&a);
		if(i==1) ans+=a*8000;
		else if(i<=n-3) ans+=8000*a;
		else if(i==n-2) ans+=6000*a;
		else if(i==n-1) ans+=4000*a;
		else ans+=a*2000; 
	}
	printf("%d",ans);
	return 0;
}
