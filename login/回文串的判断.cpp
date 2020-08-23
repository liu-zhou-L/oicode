#include<cstdio>
#include<cstring>
#define MAXN 1000
char a[MAXN+5];
bool f(char s[],int i,int j){
	if(i>=j) return true;
	if(s[i]!=s[j]) return false;
	return f(s,i+1,j-1);
}
int main()
{
	int len;
	scanf("%s",&a);
	len=strlen(a);
	bool ans=f(a,0,len-1);
	if(ans==true)
		printf("True");
	else
		printf("False");
}
