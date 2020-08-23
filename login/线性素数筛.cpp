#include<cstdio>
bool a[10000010];
int b[10000010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i+=1)
	{
		scanf("%d",&b[i]);
	}
	a[1]=1; 
	for(int i=2;i<=n;i+=1)
	{
		if(a[i]==0)
		{
			for(int j=i+i;j<=n;j+=i)
			{
				a[j]=1;
			}
		}
	} 
	for(int i=1;i<=m;i+=1){
		if(a[b[i]]==0) printf("Yes\n");
		else printf("No\n");
	}
}
