#include<cstdio>
int main(){
	long long int a,b,c,d,e=0,f=0;
	scanf("%lld %lld",&a,&b);
	if(a>b){
		d=b;
		c=a;
	}
	else{
		d=a;
		c=b;
	}
	for(int i1=d;i1<=c;i1++){
		f=0;
		for(int i2=2;i2*i2<=i1;i2++){
			if(i1%i2==0){
				f+=1;
				break;
			} 
		}
		if(f==0&&i1%10==7){
			e+=i1;
		}
	}
	printf("%lld",e);
	return 0;
} 
