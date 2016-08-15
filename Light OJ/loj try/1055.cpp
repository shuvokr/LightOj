#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(int r, int c, int flag);

int cost[ 12 ][ 12 ], n, save[ 3 ][ 3 ];
char graph[ 13 ][ 13 ];

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, kag = 0, flaging;
    scanf("%d", &T);
    while( T-- )
    {
        flaging = 48;
        scanf("%d", &n); getchar();
        for(int i = 0; i < n; i++)
        {
            gets( graph[ i ] );
            for(int j = 0; j < n; j++) if(graph[ i ][ j ] == 'X') graph[ i ][ j ] = flaging, flaging++;
        }

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) save[ i ][ j ] = 1 << 29;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(isalpha(graph[ i ][ j ]))
                {
                    puts("ok");
                    memset(cost, -1, sizeof cost);
                    BFS(i, j, graph[ i ][ j ] - 'A');
                }
            }

        int res = 1 << 30;
        for(int i = 0; i < 3; i++)
        {
            if(save[ 0 ][ i ] == 1 << 29) continue;
            for(int j = 0; j < 3; j++)
            {
                if(j == i || save[ 1 ][ j ] == 1 << 29) continue;
                for(int k = 0; k < 3; k++)
                {
                    if(k == j || k == i || save[ 2 ][ k ] == 1 << 29) continue;
                    //printf("%d %d %d\n", save[ 0 ][ i ], save[ 1 ][ j ], save[ 2 ][ k ]);
                    int tmp = max(save[ 0 ][ i ], max(save[ 1 ][ j ], save[ 2 ][ k ]));
                    res = min(res, tmp);
                }
            }
        }
        if(res == 1 << 30) printf("Case %d: trapped\n", ++kag);
        else printf("Case %d: %d\n", ++kag, res);
    }
    return 0;
}
void BFS(int r, int c, int flag)
{
    queue <int> q;
    cost[ r ][ c ] = 0;
    q.push( r ); q.push( c );
    while(!q.empty())
    {
        r = q.front(); q.pop();
        c = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int a = r + diraction1[ i ];
            int b = c + diraction2[ i ];
            if(a >= 0 && a < n && b >= 0 && b < n)
            if(graph[ a ][ b ] != '#' && cost[ a ][ b ] == -1)
            {
                cost[ a ][ b ] = cost[ r ][ c ] + 1;
                if(isdigit(graph[ a ][ b ])) save[ flag ][ graph[ a ][ b ] - 48 ] = cost[ a ][ b ];
                q.push( a ); q.push( b );
            }
        }
    }
}
