//Templet start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define pb push_back
#define maxn 200000+2
#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
int BFS(int x);

vector < int > graph[ maxn ];
bool subgraph[ maxn ];
int edge;

int main()
{
    input();

    return 0;
}
void input()
{
    int n, i, j, T, kag = 0, u, v, maxi, mini, ans;
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &n);
        fo(i, n) graph[ i ].clear();
        mem(subgraph, false);
        maxi = -1; mini = 20002;
        while(n--)
        {
            sf("%d %d", &u, &v);
            maxi = max(maxi, u);
            maxi = max(maxi, v);
            mini = min(mini, u);
            mini = min(mini, v);
            graph[ u ].pb( v );
            graph[ v ].pb( u );
            subgraph[ u ] = true;
            subgraph[ v ] = true;
        }
        ans = 0;
        for(i = mini; i <= maxi; i++)
        {
                if(subgraph[ i ])
                {
                    ans += BFS( i );
                }
        }
        pf("Case %d: %d\n", ++kag, ans);
    }
}
int BFS(int x)
{
    int i, j, tmp, wht = 1, blk = 0;
    queue <int> Q;
    Q.push( x );
    int color[ maxn ];
    //fo(i, 100) color[ i ] = 3;
    color[ x ] = white;
    subgraph[ x ] = false;
    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();

            for(i = 0; i < graph[ tmp ].size(); i++)
            {
                if(subgraph[ graph[ tmp ][ i ] ])
                {
                    subgraph[ graph[ tmp ][ i ] ] = false;
                    if(color[ tmp ] == white)
                    {
                        blk++;
                        color[ graph[ tmp ][ i ] ] = black;
                    }
                    if(color[ tmp ] == black)
                    {
                        wht++;
                        color[ graph[ tmp ][ i ] ] = white;
                    }
                    Q.push( graph[ tmp ][ i ] );
                }
            }
    }
    //pf("%d %d", wht, blk);
    if(blk > wht) return blk;
    else return wht;
}
