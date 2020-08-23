#include<cstdio>
int main() {
	int a,b,c[7],max=-999999999,sum;
	bool flag=0;
	for(int i=0;i<7;i+=1) {
		scanf("%d %d",&a,&b);
		c[i]=a+b;
		if(a+b>8){
			flag=1;
		}
		if(a+b>max){
			max=a+b;
			sum=i+1;
		}
	}
	if(flag==0) printf("0");
	else printf("%d",sum);
	return 0;
}
