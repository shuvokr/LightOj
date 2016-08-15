#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct data
{
    char name[ 25 ];
    int tot;
    bool operator<(const data &sk) const
    {
        return (tot < sk.tot);
    }
};
int main()
{
    int T, kag = 0, i, n, l, h, w;
    data in[ 102 ];
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        for( i = 0; i < n; i++ )
        {
            scanf("%s %d %d %d", in[i].name, &l, &h, &w );
            in[i].tot = w * l * h;
        }
        sort(in, in + n);
        if(in[ 0 ].tot == in[n - 1].tot) printf("Case %d: no thief\n", ++kag);
        else printf("Case %d: %s took chocolate from %s\n", ++kag, in[n - 1].name, in[0].name);
    }
    return 0;
}
