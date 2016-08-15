#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int DP(int pos, int must);
int mamo[ 110 ][ 2 ], n;
char in[ 110 ];

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %s", &n, in);
        memset(mamo, -1, sizeof mamo);
        printf("Case %d: %d\n", ++kag, DP( 0, 0 ));
    }
    return 0;
}
int DP(int pos, int must)
{
    if(pos >= n)
    {
        if( must ) return 1;
        return 0;
    }

    int &ret = mamo[ pos ][ must ];
    if(ret != -1) return ret;

    if( must ) ret = 1 + DP(pos + 2, 0);
    else if(in[ pos ] == '#') ret = min(1 + DP(pos + 2, 0), DP(pos + 1, 0));
    else ret = min(1 + DP(pos + 2, 0), DP(pos + 1, 1));

    return ret;
}
