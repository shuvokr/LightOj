#include <stdio.h>
#include <string.h>

int DP(int pos, int flag);
int mamo[ 1010 ][ 2 ], n, in[ 1010 ];

int main()
{
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n); memset(mamo, -1, sizeof mamo);
        for(int i = 0; i < n; i++) scanf("%d", &in[ i ]);
        printf("Case %d: %d\n", ++kag, DP( 0, 0 ));
    }
    return 0;
}
int DP(int pos, int flag)
{
    if(pos >= n) return 0;
    //printf("%d %d\n", pos, flag);
    if(flag && pos + 1 == n) return 0;
    int &ret = mamo[ pos ][ flag ];
    if(ret != -1) return ret;
    int a = 0, b = 0;

    if(pos == 0) a = in[pos] + DP(pos + 2, 1);
    else a = in[pos] + DP(pos + 2, flag);

    b = DP(pos + 1, flag);

    ret = a > b ? a : b;
    return ret;
}
