#include<cstdio>
int a,x=0,y=0,n;
bool flagx=1,flagy=1;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			scanf("%d",&a);
			if(a==0&&flagx==1) x++;
			if(a==0&&flagy==1) y++;
		}
		if(x>0) flagx=0;
		if(y>0) flagy=0;
	}
	printf("%d",(x-2)*(y-2));
	return 0;
} 
