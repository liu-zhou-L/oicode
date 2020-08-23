#include<cstdio>
#include<algorithm>
using namespace std;
struct stu{
	int w,v;
}a[105];
bool cmp(stu x,stu y){
	return x.v>y.v;
}
int main(){
	int m,n;
	stu hhh[105],z;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i+=1){
		scanf("%d%d",&a[i].w,&a[i].v);
	}
	sort(a+1,a+1+n,cmp);
	int tot=0,ans=0;
	for(int i=1;i<=n;i+=1){
		while(tot<m&&a[i].w!=0){
			tot+=1;
			ans+=a[i].v;
			a[i].w-=1;
		}
	}
	printf("%d",ans);
}
