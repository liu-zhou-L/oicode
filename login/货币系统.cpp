#include<cstdio>
int v,n,V[35],f[1005]={1};
int main() {
    scanf("%d%d",&v,&n);
    for(int i=1;i<=v;i++) {
        scanf("%d",&V[i]);
    }
    for(int i=1;i<=v;i++) {
    	for(int j=V[i];j<=n;j++) {
    		f[j]+=f[j-V[i]];
		} 
    }
	printf("%d",f[n]);
    return 0;
}
