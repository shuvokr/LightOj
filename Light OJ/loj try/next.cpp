#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int DP(int pos, int part);
int point, mamo[ 50010 ][ 3 ], n, k, in[ 50010 ], cou[ 110 ];

int main()
{
    int T, sum = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n); sum = 0; memset(cou, 0, sizeof cou);
        for(int i = 0; i < n; i++) scanf("%d", &in[ i ]), sum += in[ i ], cou[ in[ i ] ]++;
        memset(mamo, -1, sizeof mamo);
        scanf("%d", &k);

        if(n % k == 0)
        {
            printf("%d\n", sum);
            continue;
        }

        if(k > n)
        {
            puts("0");
            continue;
        }

        if(k == 2)
        {
            int mn = 1000000000;
            for(int i = 2; i < n - 2; i += 2) mn = mn > in[ i ] ? in[ i ] : mn;
            mn = mn > in[ 0 ] ? in[ 0 ] : mn;
            mn = mn > in[ n - 1 ] ? in[ n - 1 ] : mn;
            sum -= mn;
        }
        else
        {
            if(n % k == 1)
            {
                int mn = 1000000000;
                for(int i = 3; i < n - 3; i += 3) mn = mn > in[ i ] ? in[ i ] : mn;
                mn = mn > in[ 0 ] ? in[ 0 ] : mn;
                mn = mn > in[ n - 1 ] ? in[ n - 1 ] : mn;
                sum -= mn;
            }
            else
            {
                point = -1;
                int res = DP(0, 2);
                sum -= res;
            }
        }

        printf("%d\n", sum);
    }
    return 0;
}

/******Input*******
1
8
2 5 3 1 4 6 1 7
3
Output: 24
******************/

int DP(int pos, int part)
{
    //printf("%d %d\n", pos, part);
    if(part == 0) return 0;
    if(pos >= n)
    {
        //if(part)
        if(part) return 1000000000;
        return 0;
    }
    int &ret = mamo[ pos ][ part ];
    if(ret != -1) return ret;

    ret = 1000000000;

    if(part == 2)
    {
        if(pos % k == 0)
        {
            point = pos;
            return ret = min(in[ pos ] + DP(pos + 1, part - 1), DP(pos + 1, part));
        }
        else return ret = DP(pos + 1, part);
    }
    else if(part)
    {
        if((pos - point - 1) % k == 0) return ret = min(in[ pos ], DP(pos + 1, part));
        return ret = DP(pos + 1, part);
    }
    return ret;
}
