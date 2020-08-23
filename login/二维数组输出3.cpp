#include<cstdio>
int main(){
	int a[15][15]={0};
	int n,num=1,flag=0,y=1,x=1;
	scanf("%d",&n);
	a[y][x]=1;
	while(num<n*n){
		while(x+1<=n&&!a[y][x+1]) a[y][++x]=++num;
		while(y+1<=n&&!a[y+1][x]) a[++y][x]=++num;
		while(x-1>=1&&!a[y][x-1]) a[y][--x]=++num;
		while(y-1>=1&&!a[y-1][x]) a[--y][x]=++num;
	}
	for(y=1;y<=n;y+=1){
		for(x=1;x<=n;x+=1){
			if(flag==0){
				printf("%d",a[y][x]);
				flag=1;
			}
			else{
				printf(" %d",a[y][x]);
			}
		}
		flag=0;
		printf("\n");
	}
}
