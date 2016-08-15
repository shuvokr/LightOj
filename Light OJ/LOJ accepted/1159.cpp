#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int DP(int i, int j, int k);

int mamo[ 55 ][ 55 ][ 55 ];
char str1[ 55 ], str2[ 55 ], str3[ 55 ];

int main()
{
    int T, kag = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s %s %s", str1, str2, str3);
        memset(mamo, -1, sizeof mamo);
        printf("Case %d: %d\n", ++kag, DP(0, 0, 0));
    }

    return 0;
}
int DP(int i, int j, int k)
{
    if(i == strlen(str1) || j == strlen(str2) || k == strlen(str3)) return 0;
    if(mamo[ i ][ j ][ k ] != -1) return mamo[ i ][ j ][ k ];

    int ret = 0;

    if(str1[ i ] == str2[ j ] && str1[ i ] == str3[ k ]) ret = 1 + DP(i + 1, j + 1, k + 1);
    ret = max(ret, DP(i, j, k + 1));
    ret = max(ret, DP(i, j + 1, k));
    ret = max(ret, DP(i + 1, j, k));
    //else if(str2[ j ] == str3[ k ] && str1[ i ] != str3[ k ]) ret = DP(i, j + 1, k);
    return mamo[ i ][ j ][ k ] = ret;
}
