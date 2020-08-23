#include<cstdio>
#include<cmath>
bool f(int a,int b,int c) {
	for(int i=0;i<=sqrt(a*100+b*10+c);i+=1)
		if(i*i==a*100+b*10+c) return 1;
	return 0;
}
bool a[10];
int main() {
	for(int i=1;i<=9;i+=1)
		for(int j=0;j<=9;j+=1)
			for(int k=0;k<=9;k+=1) {
				if(f(i,j,k)&&a[i]==0&&a[j]==0&&a[k]==0) {
					printf("%d%d%d ",i,j,k);
					a[i]=a[j]=a[k]=1;
				}
			}//printf("361 529 784");
	return 0;
}
