#include<cstdio>
#include<cstring>
int main()
{
    int n,m;
    int a[5001];
    int i,j;
    int flag=1;
    scanf("%d%d",n,m);
    memset(a,0,sizeof(a));//��ʼ�����ƹ���
    for(i=1;i<=m;i++)//m�������ν��в���
        for(j=1;j<=n;j++)//��nյ�ƽ��в���
            if(j%i==0)//ֻ���˱�ŵı������в���
                a[j]=!a[j];//�Եƽ����෴����
    for(i=1;i<=n;i++)//������ǹرյ����
    {
        if(a[i])
        {
            if(flag) flag=0;//����һ�β������������
            else printf(",");
            printf("i");
        }
    }
    printf("\n");
    return 0;
} 
