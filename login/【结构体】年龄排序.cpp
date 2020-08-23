#include<cstdio>
struct stu{
	char name[20],xb[8];
	int n,y;
};
int main(){
	stu studys[110],a;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1){
		scanf("%s %s %d %d",studys[i].name,studys[i].xb,&studys[i].n,&studys[i].y);
	}
	for(int i=1;i<=n;i+=1){
		for(int j=i+1;j<=n;j+=1){
			if((studys[j].n>studys[i].n)||(studys[j].n==studys[i].n&&studys[j].y>studys[i].y)){
				a=studys[i];
				studys[i]=studys[j];
				studys[j]=a;
			}
		}	
	}
	for(int i=1;i<=n;i+=1){
		printf("%s %s %d %d\n",studys[i].name,studys[i].xb,studys[i].n,studys[i].y);
	}
}
