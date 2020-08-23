#include<cstdio>
int main(){
	char a[35],b,c;
	scanf("%s %c %c",a,&b,&c);
	for(int i=0;a[i]!='\0';i++) {
		if(a[i]==b) a[i]=c;
		printf("%c",a[i]);
	} 
	return 0;
}

