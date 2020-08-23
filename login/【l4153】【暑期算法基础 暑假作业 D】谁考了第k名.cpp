#include<cstdio>
struct stu{
	double cj;
	int xh;
};
int main(){
	stu name[110],a;
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i+=1)
	{
		scanf("%d %lf",&name[i].xh,&name[i].cj);
	}
	for(int i=1;i<=n;i+=1)
	{
		for(int j=i+1;j<=n;j+=1)
		{
			if(name[j].cj>name[i].cj)
			{
				a=name[i];
				name[i]=name[j];
				name[j]=a;
			}
		}	
	}
	printf("%d %g",name[k].xh,name[k].cj);
} 
