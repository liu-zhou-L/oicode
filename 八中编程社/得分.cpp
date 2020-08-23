#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b) { return a>b;}
int main() {
	//freopen("score.in","r",stdin);
	//freopen("score.out","w",stdout);
	int n,k,now=0,b[85]={};
	char a;
	scanf("%d%d\n",&n,&k);
	for(int i=1;i<=n;i+=1) {
		scanf("%c",&a);
		if(a=='O') now++;
		else if(a=='X') now=0;
		b[now]++;
		//printf("%d\n",now);
	}
	//for(int i=1;i<=n;i+=1) printf("%d",b[i]);
	for(int i=85;i>=0;i--) {
		if(b[i]!=0) {
			k--;
		}
		if(k==0) {
			printf("%d",i);
			break;
		}
	}
	return 0;
}
