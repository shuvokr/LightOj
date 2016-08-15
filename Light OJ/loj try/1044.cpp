#include <stdio.h>
#include <string.h>

int dp(int s, int e);
bool ispalindrom(int s, int e);

int tot, mamo[ 1002 ][ 1002 ];
char str[ 1010 ];

int main()
{
    freopen("input.txt", "r", stdin);
    int T, kag = 0;
    scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( str ); tot = 0;
        memset(mamo, -1, sizeof mamo);
        printf("Case %d: %d\n", ++kag, dp(0, strlen( str ) - 1));
        printf("%d\n\n", tot);
    }
}
int dp(int s, int e)
{

}
bool ispalindrom(int s, int e)
{
    while(s <= e)
    {
        if(str[ s ] != str[ e ]) return false;
        s++; e--;
    }
    return true;
}
