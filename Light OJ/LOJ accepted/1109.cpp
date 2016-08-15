#include <stdio.h>
#include <algorithm>
using namespace std;

struct data
{
    int number, pos;
}in[ 1005 ];

bool cmp(data a, data b)
{
    if(a.number < b.number) return true;
    if(a.number == b.number)
        if(a.pos > b.pos) return true;
    return false;
}

int main()
{
    int cou, kag = 0, T, n, i, j, lim;
    in[ 0 ].pos = 0; in[ 0 ].number = 0;
    in[ 1 ].pos = 1; in[ 1 ].number = 1;
    for(i = 2; i < 1001; i++)
    {
        cou = 0; lim = i + 1;
        for(j = 1; j < lim; j++)
            if(!(i % j)) cou++;
        in[ i ].pos = i; in[ i ].number = cou;
    }
    sort(in, in + 1001, cmp);
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", ++kag, in[ n ].pos);
    }
    return 0;
}
