#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int DP(int p1, int p2, int pn);
int mamo[ 51 ][ 51 ][ 51 ], n, a[ 55 ], res, b[ 55 ], T, kag = 0;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n); res = 0;
        for(int i = 0; i < n; i++) scanf("%d", &a[ i ]); sort(a, a + n);
        for(int i = 0; i < n; i++) scanf("%d", &b[ i ]); sort(b, b + n);
        memset(mamo, -1, sizeof mamo);
        printf("Case %d: %d\n", ++kag, DP(0, 0, n));
    }
    return 0;
}
int DP(int p1, int p2, int pn)
{
    if(p1 == n || p2 == pn) return 0;
    int &ret = mamo[ p1 ][ p2 ][ pn ];
    if(ret != -1) return ret;

    if(a[ p1 ] > b[ p2 ]) return ret = 2 + DP(p1 + 1, p2 + 1, pn);
    if(a[ p1 ] < b[ p2 ]) return ret = DP(p1 + 1, p2, pn - 1);

    int aa = 0, bb = 0;
    aa = 1 + DP(p1 + 1, p2 + 1, pn);
    if(a[ p1 ] < b[pn - 1]) bb = DP(p1 + 1, p2, pn - 1);
    return ret = max(aa, bb);
}
