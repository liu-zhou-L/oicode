#include <cstdio>
using namespace std;

int n, m, k, s;

int main() {
    while(scanf("%d%d")){
        int mi=1100;
        int a[111][111]={0};
        for(int i=0;i<k;i++)///��ȫ����
        {
            int ds,cos;
            cin>>ds>>cos;
            for(int i=cos;i<=m;i++)
            {
                for(int j=1;j<=s;j++)
                {
                    a[i][j]=max(a[i][j],a[i-cos][j-1]+ds);///��jֻ�ֻ�õľ���ֵȡ������j-1ֻ�ֵľ���ֵ����ֻ�ֵľ���ֵ
                    if( a[i][j]>=n)///ȡ�����������ѵ���С���Ͷ�
                        mi=min(i,mi);
                }
 
            }
        }
        if(mi!=1100)
            printf("%d\n",m-mi);
        else
            printf("-1\n");
    }
}
