#include<cstdio>
int main() {
	int a,k=0,l=0;
	for(int i=1;i<=3;i++) {
		for(int j=1;j<=3;j++) {
			scanf("%d",&a);
			if(i==j) k+=a;
			if(j==3-i+1) l+=a;
		}
	}
	printf("%d %d",k,l);
	return 0;
} 
