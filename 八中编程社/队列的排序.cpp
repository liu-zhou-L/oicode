#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n,b,a[1005];
	scanf("%d",&n);
	for(int i=0;i<n;i+=1)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i+=1)
		printf("%d ",a[i]);
	return 0;
}
