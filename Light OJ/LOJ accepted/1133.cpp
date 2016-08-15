#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("output.txt", "w", stdout);
    long long i, j, T, ar[ 105 ], n, q, tmp;
    char ch[ 3 ];
    int kag = 0;
    scanf("%lld", &T);
    while( T-- )
    {
        memset(ar, 0, sizeof ar);
        scanf("%lld %lld", &n, &q);
        for(i = 0; i < n; i++) scanf("%lld", &ar[ i ]);
        for(i = 0; i < q; i++)
        {
            scanf("%s", ch);
            if(ch[ 0 ] == 'S')
            {
                scanf("%lld", &tmp);
                for(j = 0; j < n; j++) ar[ j ] += tmp;
            }
            else if(ch[ 0 ] == 'M')
            {
                scanf("%lld", &tmp);
                for(j = 0; j < n; j++) ar[ j ] *= tmp;
            }
            else if(ch[ 0 ] == 'D')
            {
                scanf("%lld", &tmp);
                for(j = 0; j < n; j++) ar[ j ] /= tmp;
            }
            else if(ch[ 0 ] == 'R')
            {
                int low = 0, high = n - 1;
                while(low < high)
                    swap(ar[ low ], ar[ high ]), low++, high--;
            }
            else if(ch[ 0 ] == 'P')
            {
                int a, b;
                scanf("%d %d", &a, &b);
                swap(ar[ a ], ar[ b ]);
            }
        }
        printf("Case %d:\n%lld", ++kag, ar[ 0 ]);
        for(i = 1; i < n; i++) printf(" %lld", ar[ i ]);
        puts("");
    }
    return 0;
}
