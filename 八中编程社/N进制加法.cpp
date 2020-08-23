#include<cstdio>
#include<cstring>
int n,a[5055],b[5055],c[5100],lena,lenb,lenc=1;
char s1[5055],s2[5055];
int main() {
	scanf("%d %s%s",&n,s1,s2);
	lena=strlen(s1);
	lenb=strlen(s2);
	for(int i=0;i<lena;i++) {
		if(s1[i]>='0'&&s1[i]<='9') a[lena-i]=s1[i]-48;
		else a[lena-i]=s1[i]-55;
	}
	for(int i=0;i<lenb;i++) {
		if(s2[i]>='0'&&s2[i]<='9') b[lenb-i]=s2[i]-48;
		else  b[lenb-i]=s2[i]-55;
	}
	int x=0;
	lenc=1;
	while(lenc<=lena||lenc<=lenb) {
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/n;
		c[lenc]%=n;
		lenc++;
	}
	c[lenc]=x;
	while(c[lenc]==0&&lenc>1) lenc--;
	for(int i=lenc;i>=1;i--) {
		if(c[i]>=0&&c[i]<=9) printf("%d",c[i]);
		else printf("%c",c[i]+55);
	}
	return 0;
}
