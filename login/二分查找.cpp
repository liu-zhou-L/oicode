/*#include<cstdio>
int a[2000010];
int main()
{
	int N,X,n;
	bool flag=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i+=1)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&X);
	n=N;
	while(a[n]!=X)
	{
		if(a[n]>X) n/=2;
		if(a[n]<X) n+=n/2;
		
	}
	printf("%d",n);
}*/
#include<cstdio>
int a[2000005],x;
void find(int l,int r){
	if(l>r){
		printf("-1");
		return;
	}
	int mid=(l+r)/2;
	if(a[mid]==x){
		printf("%d",mid);
		return;
	}
	else if(a[mid]>x){
		find(l,mid-1);
	}
	else if(a[mid]<x){
		find(mid+1,r);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&x);
	find(1,n);
	return 0;
} 
