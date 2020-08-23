#include<cstdio>
int main() {
	int n,a,b,an[105],bn[105],j=0,m=0,js=0;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&an[i]);
	for(int i=1;i<=b;i++) scanf("%d",&bn[i]);
	for(int i=1;i<=n;i+=1) {
		j++;m++;
		if(j>a) j=1;
		if(m>b) m=1;
		if(an[j]==0) {
			if(bn[m]==2) js++;
			else if(bn[m]==5) js--;
		}
		else if(an[j]==2)
		{
			if(bn[m]==5) js++;
			else if(bn[m]==0) js--;
		}
		else {
			if(bn[m]==0) js++;
			else if(bn[m]==2) js--;
		}
	}
	if(js<0) printf("B");
	else if(js>0) printf("A");
	else printf("draw");
	return 0;
}
