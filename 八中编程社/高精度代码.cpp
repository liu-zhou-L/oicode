#include<cstdio>
#include<cstring>
int maxn(int a,int b) { return a>b?a:b;}
const int yw=10000;
int a[5055],b[5055],c[5100],lena,lenb,lenc=1,s3;
char s1[5055],s2[5055];
void long_add() {
	scanf("%s%s",s1,s2);
	lena=strlen(s1);
	lenb=strlen(s2);
	for(int i=0;i<lena;i++) {
		a[lena-i]=s1[i]-48;
	}
	for(int i=0;i<lenb;i++) {
		b[lenb-i]=s2[i]-48;
	}
	int x=0;
	lenc=1;
	while(lenc<=lena||lenc<=lenb) {
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}
	c[lenc]=x;
	while(c[lenc]==0&&lenc>1) lenc--;
	for(int i=lenc;i>=1;i--) printf("%d",c[i]);
}
void long_sub() {
	scanf("%s%s",s1,s2);
	char n[5055];
	if(strlen(s1)<strlen(s2)||(strlen(s1)==strlen(s2)&&strcmp(s1,s2)<0)) {
		strcpy(n,s1);
		strcpy(s1,s2);
		strcpy(s2,n);
		printf("-");
	}
	lena=strlen(s1);
	lenb=strlen(s2);
	for(int i=0;i<lena;i++) {
		a[lena-i]=s1[i]-48;
	}
	for(int i=0;i<lenb;i++) {
		b[lenb-i]=s2[i]-48;
	}
	lenc=1;
	while(lenc<=lena) {
		if(a[lenc]<b[lenc]) {
			a[lenc]+=10;
			a[lenc+1]--;
		}
		c[lenc]=a[lenc]-b[lenc];
		lenc++;
	}
	while(c[lenc]==0&&lenc>1) lenc--;
	for(int i=lenc;i>=1;i--) printf("%d",c[i]);
}
void long_mul() {
	scanf("%s%s",s1,s2);
	int x,len;
	lena=strlen(s1)%4==0?strlen(s1)/4:strlen(s1)/4+1;
	lenb=strlen(s2)%4==0?strlen(s2)/4:strlen(s2)/4+1;
	/*for(int i=0;i<lena;i++) {
		a[lena-i]=s1[i]-48;
	}
	for(int i=0;i<lenb;i++) {
		b[lenb-i]=s2[i]-48;
	}*/
	for(int i=0,len=strlen(s1);i<lena;i++) {
		int t=0;
		for(int j=maxn(0,len-4*(i+1));j<len-4*i;j++) t=t*10+(a[j]-48);
		a[i+1]=t;
	}
	for(int i=0,len=strlen(s2);i<lenb;i++) {
		int t=0;
		for(int j=maxn(0,len-4*(i+1));j<len-4*i;j++) t=t*10+(b[j]-48);
		b[i+1]=t;
	}
	/*for(int i=1;i<=lena;i++) {
		x=0;
		for(int j=1;j<=lenb;j++) {
			c[i+j-1]+=a[i]*b[j]+x;
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+lenb]=x;
	}*/
	for(int i=1;i<=lena;i++) {
		x=0;
		for(int j=1;j<=lenb;j++) {
			c[i+j-1]+=a[i]*b[j]+x;
			x=c[i+j-1]/yw;
			c[i+j-1]%=yw;
		}
		c[i+lenb]=x;
	}
	lenc=lena+lenb;
	while(c[lenc]==0&&lenc>1) lenc--;
	printf("%d",c[lenc]);
	for(int i=lenc-1;i>=1;i--) printf("%04d",c[i]);
}
void long_div() {
	scanf("%s%d",s1,&s3);
	int x=0;
	bool flag=0;
	lena=strlen(s1);
	for(int i=1;i<=lena;i++) {
		a[i]=s1[i-1]-48;
	}
	for(int i=1;i<=lena;i++) {
		c[i]=(x*10+a[i])/s3;
		x=(x*10+a[i])%s3;
	}
	for(int i=1;i<=lena;i++) {
		if(c[i]!=0) flag=1;
		if(flag==1||i==lena) printf("%d",c[i]);
	}
}
int main() {
	long_add();
	return 0;
}
