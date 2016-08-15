#include <cstdio>
#include <cstring>

int dp(int r, int flag);

int mamo[ 22 ][ 4 ], n, in[ 22 ][ 4 ];

int main()
{
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d %d %d", &in[ i ][ 1 ], &in[ i ][ 2 ], &in[ i ][ 3 ]);
        memset(mamo, -1, sizeof mamo);
        printf("Case %d: %d\n", ++kag, dp(0, 0));
    }
    return 0;
}
int dp(int r, int flag)
{
    if(r == n) return 0;
    if(mamo[ r ][ flag ] != -1) return mamo[ r ][ flag ];
    int a = 1 << 29, b = 1 << 29, c = 1 << 29;
    if(flag != 1) a = in[ r ][ 1 ] + dp(r + 1, 1);
    if(flag != 2) b = in[ r ][ 2 ] + dp(r + 1, 2);
    if(flag != 3) c = in[ r ][ 3 ] + dp(r + 1, 3);
    a = a < b ? a : b;
    a = a < c ? a : c;
    return mamo[ r ][ flag ] = a;
}
