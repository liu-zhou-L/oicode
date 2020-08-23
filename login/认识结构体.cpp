#include<cstdio>
#include<cstring>
#define MAXN 20
struct stu{
	char name[MAXN+5];
	int score;
};
int main(){
	stu s1,s2;
	s1.score =100;
	strcpy(s1.name,"Lihong");
	scanf("%d %s",&s2.score,s2.name);
	printf("%s %d\n",s1.name,s1.score);
	printf("%s %d\n",s2.name,s2.score);
}
