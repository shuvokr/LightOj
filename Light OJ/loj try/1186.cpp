#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int a[ 110 ], b [ 110 ], n, T, kag = 0, x;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        for(int i = 0; i < n ; i++) scanf("%d", &a[ i ]);
        for(int i = 0; i < n ; i++) scanf("%d", &b[ i ]);

        x = 0;
        for(int i = 0; i < n; i++)
            x += abs(a[ i ] - b[ i ]) - 1;

        if(x % 2) printf("Case %d: white wins\n", ++kag);
        else printf("Case %d: black wins\n", ++kag);
    }
    return 0;
}
