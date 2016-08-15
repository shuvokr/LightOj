#include <cstdio>
#include <cstring>

int main()
{
    int T, kag = 0;
    char in[ 10 ];
    scanf("%d", &T);
    while( T-- )
    {
        int t;
        scanf("%d %s", &t, in);
        printf("Case %d: ", ++kag);
        if(in[ 0 ] == 'B' && t % 3) puts( in );
        else if(in[ 0 ] == 'B')puts("Alice");
        else if(in[ 0 ] == 'A' && t % 3 == 1) puts( "Bob" );
        else puts(in);
    }
    return 0;
}
