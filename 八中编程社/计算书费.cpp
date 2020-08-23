#include<cstdio>
int main(){
	double n,a[15]={0,28.9,32.7,45.6,78,35,86.2,27.8,43,56,65},ans=0;
	for(int i=1;i<=10;i+=1) {
		scanf("%lf",&n);
		ans+=n*a[i];
	}
	printf("%.1lf",ans);
	return 0;
}
