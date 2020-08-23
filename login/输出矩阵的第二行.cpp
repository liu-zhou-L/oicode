#include<cstdio>
int main(){
	int a[4][5],flag=0;
	for(int i=0;i<=3;i+=1){
		for(int n=0;n<=4;n+=1){
			scanf("%d",&a[i][n]);
		} 
	}
	for(int i=1;i==1;i+=1){
		for(int n=0;n<=4;n+=1){
			if(n==0){
				printf("%d",a[i][n]);
				flag=1;
			}
			else{
				printf(" %d",a[i][n]);
			} 
		}
	}
} 
