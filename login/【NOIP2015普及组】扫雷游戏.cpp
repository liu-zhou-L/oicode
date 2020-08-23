#include<cstdio>
int main(){
	char a[110][110],b[110][110];
	int y,x,sum;
	scanf("%d%d",&y,&x);
	for(int i=1;i<=y;i+=1){
		scanf("%s",&a[i][1]);
	}
	for(int i=1;i<=y;i+=1){
		for(int j=1;j<=x;j+=1){
			sum=0;
			if(a[i][j]!='*'){
				for(int u=-1;u<=1;u+=1){
					for(int v=-1;v<=1;v+=1){
						if((u!=0&&v!=0)&&a[u][v]=='*'){
							sum+=1;
						}
					}
				} 
				b[i][j]=sum+'0';
			}
		}
	}
	for(int i=1;i<=y;i+=1){
		for(int j=1;j<=x;j+=1){
			if(a[i][j]!='*')
				printf("%c",b[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}
}
