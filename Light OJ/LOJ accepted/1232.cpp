#include <cstdio>
#include <cstring>

int res[ 10005 ], n, k, coin, mod = 100000007;

int main()
{
    int T, kag = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &k);
        memset(res, 0, sizeof res);
        res[ 0 ] = 1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &coin);
            for(int j = coin; j <= k; j++)
            {
                res[ j ] += res[ j - coin ];
                if(res[ j ] > mod) res[ j ] %= mod;
            }
        }
        printf("Case %d: %d\n", ++kag, res[ k ]);
    }
    return 0;
}
