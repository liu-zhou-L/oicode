#include<cstdio>
int main(){
	int i;
	double a=0,b=0,c=0,d=0,n;
	scanf("%lf",&n);
	for(int j=1;j<=n;j++) {
		scanf("%d",&i);
		if(i<=18) a+=1;
		else if(i>18&&i<=35) b+=1;
		else if(i>35&&i<=60) c+=1;
		else d+=1;
	}
	printf("%.2lf%\n%.2lf%\n%.2lf%\n%.2lf%\n",a/n*100,b/n*100,c/n*100,d/n*100);
	return 0;
}
