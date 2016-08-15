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
#define maxn 10000+2

#define green 0
#define blue 1
#define red 2
#define pb push_back

typedef vector <int> vi;
typedef vector <bool> vb;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
void cycle_cheak( int sorce );

map <string, int> m;
vector <int> graph[ maxn ];
int edge, k, color[ maxn ];
bool mark[ maxn ], ck;

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j, kag = 0, n, cou;
    char drink1[ 11] , drink2[ 11 ];

    sf("%d", &T);
    while(T--)
    {
        sf("%d", &edge); k = 0;
        m.clear();

        fo(i, edge)
        {
            sf("%s %s", drink1, drink2);
            if(!m[ drink1 ]) m[ drink1 ] = ++k;
            if(!m[ drink2 ]) m[ drink2 ] = ++k;
            graph[ m[ drink1 ] ].pb( m[ drink2 ] );
        }

        fo(j, k + 1) color[ j ] = green;
        ck = true;
        cou = 0;
        for(i = 1; i<= k; i++)
        {
            if(!mark[ i ]) cycle_cheak( i );
            if(!ck) i = k + 1;
        }
        if(ck)
        {
            bool sk = true;
            for(i = 1; i <= k; i++) // if any drink he do not drink then its no else yes
            {
                if(!mark[ i ])
                {
                    sk = false;
                    i = k + 1;
                }
            }
            if(sk) pf("Case %d: Yes\n", ++kag);
            else pf("Case %d: No\n", ++kag);
        }
        else pf("Case %d: No\n", ++kag);
        fo(i, k+1)
        {
            graph[ i ].clear();
            mark[ i ] = false;
        }
    }
}
void cycle_cheak( int sorce )
{
    if(color[ sorce ] == blue)
    {
        ck = false;
        return;
    }
    else if(color[ sorce ] == green)
    {
    mark[ sorce ] = true; // Its mark which drink he drunk
    color[ sorce ] = blue;
    if(color[ sorce ] == blue)
        for(int i = 0; i < graph[ sorce ].size(); i++)
        {
            //if(color[ graph[ sorce ][ i ]  ] == green)
                cycle_cheak( graph[ sorce ][ i ] );
        }
    color[ sorce ] = red;
    }
}
