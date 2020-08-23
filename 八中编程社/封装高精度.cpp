#include<cstdio>
#include<cstring>
struct vlong {
	int k[8005],len;
}a,b,c;
int read(vlong &k) {
	char s[8005];
	scanf("%s",s);
	getchar();
	k.len=strlen(s);
	for(int i=0;i<k.len;i++) {
		k.k[k.len-i]=s[i]-48;
	}
	return k.len;
}
void add(vlong &k,vlong &l,vlong &z) {
	int x=0;
	z.len=1;
	while(z.len<=k.len||z.len<=l.len) {
		z.k[z.len]=k.k[z.len]+l.k[l.len]+x;
		x=z.k[z.len]/10;
		z.k[z.len]%=10;
		z.len++;
	}
	z.k[z.len]=x;
	while(z.k[z.len]==0&&z.len>1) z.len--;	
}
void write(vlong &k) {
	for(int i=k.len;i>=1;i--) printf("%d",k.k[i]);
	printf("\n");
}
int main() {
	read(a);
	read(b);
	add(a,b,c);
	//write(a);
	//write(b);
	write(c);
	return 0;
} 
