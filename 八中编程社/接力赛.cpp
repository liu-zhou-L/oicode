#include<cstdio>
#include<stdio.h>
double m[10],dr,now1=0,now2=0,num=0;
int ans=0;
int main() {
	for(int i=1;i<=8;i++) {
		scanf("%lf",&m[i]);
		num+=m[i];
	}
	scanf("%lf",&dr);
	for(int a=1;a<=1;a++) {
		for(int b=a+1;b<=8;b++) {
			for(int c=b+1;c<=8;c++) {
				for(int d=c+1;d<=8;d++) {
					if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d) {
						now1=m[a]+m[b]+m[c]+m[d];
						now2=num-now1;
						if(now1<dr&&now2<dr) {
							printf("%d %d %d %d\n",a,b,c,d);
							for(int i=1;i<=8;i++) {
								if(i!=a&&i!=b&&i!=c&&i!=d) printf("%d ",i);
							}
							printf("\nT1=%.2lf T2=%.2lf\n\n",now1,now2);
							ans++;
						}
					}
				}
			}
		}
	}
	//printf("%lf ",dr);
	printf("%d",ans);
	return 0;
} 
