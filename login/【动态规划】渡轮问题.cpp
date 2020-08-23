#include<cstdio>
#include<algorithm>
using namespace std;
struct cs {
	int c,d;
}a[5005];
int b[5005];
int main() {
	int x,y,n;
	scanf("%d%d%d",&x,&y,&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i].c,&a[i].d);
	}
	int maxx=-1,b[5005]={};
    b[1]=1;
    for(int i=2;i<=n;i+=1) {
        for(int j=1;j<i;j+=1) {
            if(a[i].d>=a[j].d) {
                b[i]=b[j]+1>b[i]?b[j]+1:b[i];
            }
            if(b[i]>maxx) maxx=b[i];
        }
    }
	
	return 0;
}
