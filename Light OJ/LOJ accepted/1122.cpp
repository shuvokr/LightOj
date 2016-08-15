#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int dp(int pos, int cou);

vector <int> p;
int m, n, in[ 10 ], mamo[ 12 ][ 12 ], res;
bool done[ 12 ][ 12 ];

int main()
{
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; i ++) scanf("%d", &in[ i ]);
        memset(mamo, -1, sizeof mamo);
        res = 0;
        for(int i = 0; i < m; i++)
        {
            memset(done, true, sizeof done);
            //p.push_back( in[i] );
            res += dp(i, 1);
            //p.pop_back();
            //puts("");
        }
        printf("Case %d: %d\n", ++kag, res);
    }
    return 0;
}
int dp(int pos, int cou)
{
    //printf("%d ", cou);
    if(cou == n)
    {
        //for(int i = 0; i < p.size(); i++) printf("%d", p[ i ]);
        //puts("");
        return 1;
    }
    if(mamo[ pos ][ cou ] != -1) return mamo[ pos ][ cou ];
    int ret = 0;
    for(int i = 0; i < m; i++)
    {
        int tmp = abs(in[ pos ] - in[ i ]);
        if(tmp < 3)
        {
            //p.push_back(in[ i ]);
            ret += dp(i, cou + 1);
            //p.pop_back();
        }
    }
    return mamo[ pos ][ cou ] = ret;
}
