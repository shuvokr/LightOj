#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector <int> vi;

void BFS(int s);

vector <vi> graph;
bool vis[ 10010 ];
int mark[ 10010 ], fl;
int node, edge, res;

int main()
{
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &node, &edge);

        graph.assign(node + 10, vi());
        for(int i = 0, a, b; i < edge; i++)
        {
            scanf("%d %d", &a, &b);
            graph[ a ].push_back( b );
        }

        memset(vis, true, sizeof vis); fl = 0;
        res = 0; memset(mark, 0, sizeof mark);
        for(int i = 1; i <= node; i++)
        {
            if( vis[ i ] )
            {
                fl++, BFS( i ), res++;
            }
        }
        printf("Case %d: %d\n", ++kag, res);
    }
    return 0;
}
void BFS(int s)
{
    bool check[ 10010 ];
    memset(check, true, sizeof check);
    queue <int> q; q.push( s );
    vis[ s ] = false; mark[ s ] = fl;
    while(!q.empty())
    {
        s = q.front(); q.pop();
        for(int i = 0; i < graph[ s ].size(); i++)
        {
            int d = graph[ s ][ i ];
            printf("%d %d %d, %d\n", s, d, check[ mark[ d ] ], mark[ d ]);
            if(vis[ d ])
            {
                vis[ d ] = false;
                q.push( d ); mark[ d ] = fl;
            }
            else
            {
                if(mark[ d ] && mark[ d ] != fl && check[ mark[ d ] ])
                {
                    check[ mark[ d ] ] = false;
                    res--;
                }
            }
        }
    }
}
