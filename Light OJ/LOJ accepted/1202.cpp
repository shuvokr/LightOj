#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, r1, r2, c1, c2, T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        a = abs(r1 - r2);
        b = abs(c1 - c2);
        if(a == b) printf("Case %d: 1\n", ++kag);
        else if( (!((r1 + r2) % 2) && (c1 + c2) % 2) || ((r1 + r2) % 2 && !((c1 + c2) % 2) ))
            printf("Case %d: impossible\n", ++kag);
        else printf("Case %d: 2\n", ++kag);
    }
    return 0;
}
