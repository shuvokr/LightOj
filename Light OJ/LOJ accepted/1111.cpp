#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
typedef vector <int> vi;
void BFS(int s);
vector <vi> graph;
int res_cou[ 1010 ], fl, K, N, M;
bool vis[ 1010 ];
vector <int> pos;
int main()
{
    //freopen("input.txt", "r", stdin);
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d %d", &K, &N, &M);

        pos.clear();
        for(int i = 0, tmp; i < K; i++) scanf("%d", &tmp), pos.push_back( tmp );

        graph.assign(N + 10, vi());
        for(int i = 0, a, b; i < M; i++)
        {
            scanf("%d %d", &a, &b);
            graph[a].push_back( b );
        }

        memset(res_cou, 0, sizeof res_cou);
        for(int i = 0; i < K; i++)
        {
            memset(vis, true, sizeof vis);
            BFS( pos[ i ] );
        }

        //for(int i = 1; i <= N; i++) printf("%d ", res_cou[ i ]); puts("");

        int res = 0;
        for(int i = 1; i <= N; i++) if(res_cou[ i ] == K) res++;
        printf("Case %d: %d\n", ++kag, res);
    }
    return 0;
}
void BFS(int s)
{
    queue <int> q; res_cou[ s ]++;
    q.push( s ); vis[ s ] = false;
    while(!q.empty())
    {
        s = q.front(); q.pop();
        for(int i = 0; i < graph[ s ].size(); i++)
        {
            int d = graph[ s ][ i ];
            if(vis[ d ])
            {
                vis[ d ] = false;
                res_cou[ d ]++;
                q.push( d );
            }
        }
    }
}
