#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
    int x, y[ 50005 ], w, T, kag = 0, n;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &n, &w);
        for(int i = 0; i < n; i++) scanf("%d %d", &x, &y[ i ]);
        sort(y, y + n);
        int cou = 0, cost = 0;
        for(int i = 1; i < n; i++)
        {
            cost += abs(y[i - 1] - y[ i ]);
            if(cost > w)
            {
                cou += (cost / w);
                cost %= w;
            }
        }
        if( !cou || cost ) cou++;
        printf("Case %d: %d\n", ++kag, cou);
    }
    return 0;
}
