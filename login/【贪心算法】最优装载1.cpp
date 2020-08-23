#include<cstdio>
int main(){
	int n,c,a[1005],b,sum=0,c2=0;
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i+=1){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i+=1){
		for(int j=i+1;j<=n;j+=1){
			if(a[i]>a[j]){
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	for(int i=1;i<=n;i+=1){
		if(c2+a[i]<=c){
			sum+=1;
			c2+=a[i];
		}
	}
	printf("%d",sum);
}
