#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

void BFS(int r, int c, int flag);

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};

char graph[ 15 ][ 15 ];
int n, k, cou, cost[ 15 ][ 15 ];
bool mark[ 15 ][ 15 ];

int main()
{
    int T, kag = 0, r, c;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n); getchar(); k = 0; r = c = -1;
        for(int i = 0; i < n; i++)
        {
            gets(graph[ i ]);
            for(int j = 0; j < n; j++)
            {
                if(graph[ i ][ j ] >= 'A' && graph[ i ][ j ] <= 'Z')
                {
                    k++; if(graph[ i ][ j ] == 'A') r = i, c = j;
                }

                cost[ i ][ j ] = 1 << 30;
            }
        }

        memset(mark, true, sizeof mark);
        printf("Case %d: ", ++kag); k--;
        if(r == -1) {puts("0"); continue;}

        cou = cost[ r ][ c ] = 0; BFS(r, c, 1);
        if( k ) puts("Impossible");
        else printf("%d\n", cou);
    }
    return 0;
}
void BFS(int r, int c, int flag)
{
    if( !k ) return;
    queue <int> Q; cost[ r ][ c ] = 0; mark[ r ][ c ] = false;
    Q.push( r ); Q.push( c ); graph[ r ][ c ] = '.';
    while(!Q.empty() && k)
    {
        r = Q.front(); Q.pop();
        c = Q.front(); Q.pop();
        for(int i = 0; i < 4 && k; i++)
        {
            int a = r + diraction1[ i ];
            int b = c + diraction2[ i ];
            if(mark[ a ][ b ] && a < n && a >= 0 && b < n && b >= 0 &&  (graph[ a ][ b ] == '.' || graph[ a ][ b ] - 'A' == flag))
            {
                if(graph[ a ][ b ] == '.')
                {
                    cost[ a ][ b ] = cost[ r ][ c ] + 1;
                    Q.push( a ); Q.push( b ); mark[ a ][ b ] = false;
                }
                else
                {
                    cou += cost[ r ][ c ] + 1;
                    while(!Q.empty()) Q.pop();
                    memset(mark, true, sizeof mark);
                    k--; BFS(a, b, flag + 1); // Recursive BFS code :)
                }
            }
        }
    }
}
