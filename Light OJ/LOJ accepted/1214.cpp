#include <stdio.h>
#include <string.h>
int main()
{
    long len, i, T, tmp, kag = 0, remainder, b;
    char a[ 210 ];
    scanf("%ld", &T);
    while( T-- )
    {
        scanf("%s %ld", a, &b);
        len = strlen( a );
        i = (a[ 0 ] == '-') ? 1 : 0;
        remainder = 0;
        for(; i < len; i++)
            remainder = ((remainder * 10) + a[ i ] - 48) % b;
        if( !remainder ) printf("Case %d: divisible\n", ++kag);
        else printf("Case %ld: not divisible\n", ++kag);
    }
    return 0;
}
