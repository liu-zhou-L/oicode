#include <cstdio>
using namespace std;

int n, m, k, s;

int main() {
    while(scanf("%d%d")){
        int mi=1100;
        int a[111][111]={0};
        for(int i=0;i<k;i++)///完全背包
        {
            int ds,cos;
            cin>>ds>>cos;
            for(int i=cos;i<=m;i++)
            {
                for(int j=1;j<=s;j++)
                {
                    a[i][j]=max(a[i][j],a[i-cos][j-1]+ds);///打j只怪获得的经验值取本身或打j-1只怪的经验值加这只怪的经验值
                    if( a[i][j]>=n)///取能升级所花费的最小忍耐度
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
