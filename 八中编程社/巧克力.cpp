#include<cstdio>
int main() {
	int h,w,minn=999999999;
	scanf("%d%d",&h,&w);
	if(h%3==0||w%3==0) {
		printf("0");
		return 0;	
	}
	for(int i=1;i<=h-2;i++) {
		minn=min(minn,jdz(i*w-(h-i)/2*w));
	}
	for(int i=1;i<=w-2;i++) {
		minn=min(minn,jdz(i*h-(w-i)/2*h));
	}
	for(int i=1;i<=h-1;i++) {
		if()
		minn=
	}
	return 0;
} 
