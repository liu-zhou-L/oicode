#include<cstdio>
int sum=0;
bool hws(int n) {
	int sum=0,a=n;
	while(a!=0){
		sum=sum*10+a%10;
		a/=10;
	}
	if(sum==n) return 1;
	return 0;
}
bool f(int n) {
	for(int i=2;i*i<=n;i+=1)
		if(n%i==0) return 0;
		
	return 1;
}
int main() {
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=m;i<=n;i+=1) {
		if(hws(i)&&f(i)){
			printf("%d\n",i);
			sum+=1;
		}
	}
	printf("%d",sum);
}
