#include<cstdio>
const double jd=1e300;
int main() {
	double a,b,c,d,ans=0;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(int i=1;;i++) {
		switch (i%4) {
			case 1:ans+=1/a*jd;break;
			case 2:ans-=1/b*jd;break;
			case 3:ans+=1/c*jd;break;
			case 0:ans-=1/d*jd;break;
		}
		if(ans/jd>=1) {
			double t=ans/jd-1;
			ans=i;
			switch (i%4) {
				case 1:t=t*a;break;
				case 3:t=t*c;break;
			}
			ans-=t;
			break;
		}
	}
	printf("%.2lf",ans);
	return 0;
}
