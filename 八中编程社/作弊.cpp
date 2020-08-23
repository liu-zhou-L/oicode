#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int a[5],ans=0,t;
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	sort(a,a+2);
	ans+=a[2]-a[1];
	t=a[2]-a[0];
	if(t%2==0) ans+=t/2;
	else ans+=t/2+2;
	printf("%d",ans);
	return 0;
}
