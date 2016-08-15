#include <cstdio>
#include <cstring>

long long dp(int r, int tot);
bool isok(int r, int c);


long long mamo[ 32 ][ 905 ], n, k;
bool mark[ 32 ][ 32 ];

int main()
{
    int T, kag = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &k);
        memset(mamo, -1, sizeof mamo);
        memset(mark, true, sizeof mark);
        printf("Case %d: %lld\n", ++kag, dp(0, 0));
    }
    return 0;
}
long long dp(int r, int tot)
{
    if(tot == k) return 1;
    if(r == n) return 0;
    if(mamo[ r ][ tot ] != -1) return mamo[ r ][ tot ];
    long long res = 0;
    res = dp(r + 1, tot);
    for(int c = 0; c < n; c++)
    {
        if(isok(r, c))
        {
            mark[ r ][ c ] = false;
            res += dp(r + 1, tot + 1);
            mark[ r ][ c ] = true;
        }
    }
    return mamo[ r ][ tot ] = res;
}
bool isok(int r, int c)
{
    for(int i = 0; i < n; i++)
    {
        if(!mark[ r ][ i ]) return false;
        if(!mark[ i ][ c ]) return false;
    }
    return true;
}
