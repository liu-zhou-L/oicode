#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,a[105],sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i+=1){
		for(int j=1;j<=i;j+=1){
			sum+=a[j];
		}
	}
	printf("%d",sum);
}
