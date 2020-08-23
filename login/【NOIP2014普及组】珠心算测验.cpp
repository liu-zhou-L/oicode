#include<cstdio>
int main(){
	int n,sum=0,a[110]={0},vis[20005]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1){
		scanf("%d",&a[i]);
		vis[a[i]]+=1;
	}
	for(int i=1;i<=n;i+=1){
		for(int j=1;j<=n;j+=1){
			if(vis[a[i]+a[j]]==1 && i!=j){
				vis[a[i]+a[j]]=2;
				sum+=1;
			}	
		}	
	}
	printf("%d",sum);
}
