#include<cstdio>
int f(int a,int b,int p){
	int ans=1%p;
	for(;b;b=b>>1) {
		if(b&1) ans=(long long)ans*a%p;
		a=(long long)a*a%p;
		//printf("%d\n",b);
	}
	return ans;
}
int main() {
	int a,b,p;
	scanf("%d%d%d",&a,&b,&p);
	printf("%d",f(a,b,p));
	return 0;
}
