#include<cstdio>
int pell(int a,int b){
	int sum=1;
	if(a==0){
		return sum;
	}
	sum+=2*pell()+b;
	a-=1;
}
int main(){
	int n,a,b;
	scanf("%d",&n);
	for(;n>0;n-=1){
		scanf("%d",&a);
		b=pell(a,2);
		printf("%d",b);
	}
}
