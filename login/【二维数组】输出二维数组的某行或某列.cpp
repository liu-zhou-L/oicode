#include<cstdio>
int main(){
	int x,y,a[110][110],flag,l;
	scanf("%d%d",&y,&x);
	for(int i=1;i<=y;i+=1){
		for(int j=1;j<=x;j+=1){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d%d",&flag,&l);
	if(flag==1){
		for(int i=1;i<=y;i+=1){
			printf("%d ",a[i][l]);
		}
	}
	else{
		for(int j=1;j<=x;j+=1){
			printf("%d ",a[l][x]);
		}
	}
}
