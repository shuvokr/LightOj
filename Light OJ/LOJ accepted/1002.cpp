/************************************

    Shuvo
    Problem name :
    Problem ID   :
    Problem algo :
    Note         :

*************************************/

/**********************************Templet start***********************************/
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
#include <set>
#include <algorithm>

using namespace std;

#define phl puts("Hello")
#define sf scanf
#define pf printf
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define CLR(n, v) memset(n, v, sizeof( n ))
#define INF 1 << 30
#define pb push_back
#define maxn 200+2
#define lim(v) v.begin(), v.end()
#define sz(v) ((int)v,size())
#define equals(a, b) (fabs(a-b)<eps)

#define white 0
#define black 1

const double PI = 2 * acos ( 0.0 );
const double eps = 1e-9;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pi;
typedef  vector<int> vi;
typedef vector<pi> vpi;

template <class T> T jog(T a, T b) { return a + b; }
template <class T> T bog(T a, T b) { return a - b; }
template <class T> T gon(T a, T b) { return a * b; }
template <class T> T sq(T x) {return x * x;}
template <class T> T gcd( T a, T b ) { return b == 0 ? a : gcd(b, a % b); }
template <class T> T lcm ( T a, T b ) { return ( a / gcd ( a, b ) ) * b; }
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
template <class T> T cordinatlenth(T a, T b, T c, T d) { return sqrt( sq(a - c) + sq(b - d) ); }
lld bigmod ( lld a, lld p, lld mod )
{
    lld res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}
//const int pr = 500001;
//int prime[ 41539 ], ind;
//bool mark[ pr ];
//void primelist()
//{
//    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
//    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
//    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
//        if(mark[ i ])
//            for(int j = i << 1; j < pr; j += i) mark[ j ] = false;
//    prime[ 0 ] = 2; ind = 1;
//    for(int i = 3; i < pr; i += 2)
//        if(mark[ i ]) ind++; printf("%d\n", ind);
//}

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

struct data
{
    int u, v, cost;
}in[ 16005 ];
bool cmp(const data x, const data y)
{
    return (x.cost < y.cost);
}

int find(int X);
void DFS(int u);
void find_res(int s);

int node, edge, par[ 510 ], t, maxr;
int wight[ 505 ][ 505 ], gpr[ 510 ];
vector <vi> graph;
bool mark[ 505 ], ifposi;

int main()
{
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &node, &edge);
        CLR(wight, -1); int edg = 0;
        for(int i = 0; i < edge; i++)
        {
            int u, v, cs;
            scanf("%d %d %d", &u, &v, &cs);
            if(wight[ u ][ v ] == -1 || wight[ u ][ v ] > cs)
            {
                in[edg].u = u; in[edg].v = v; in[edg].cost = cs;
                wight[ in[edg].u ][ in[edg].v ] = in[edg].cost;
                wight[ in[edg].v ][ in[edg].u ] = in[edg].cost;
                edg++;
            }
        }
        sort(in, in + edg, cmp);
        for(int i = 0; i < node; i++) par[ i ] = i;
        graph.assign(node, vi());
        for(int i = 0; i < edg; i++)
        {
            int a = in[i].u, b = in[i].v;
            a = find( a ); b = find( b );
            if(a != b)
            {
                graph[ in[i].u ].push_back( in[i].v );
                graph[ in[i].v ].push_back( in[i].u );
                par[ b ] = a;
            }
        }
        CLR(mark, true);
        CLR(gpr, -1);
        scanf("%d", &t); mark[ t ] = false;
        DFS( t ); printf("Case %d:\n", ++kag);
        for(int i = 0; i < node; i++)
        {
            maxr = 0;
            ifposi = false;
            if(i != t) find_res( i );
            else ifposi = true;
            if( ifposi ) printf("%d\n", maxr);
            else puts("Impossible");
        }
    }
}
int find(int X)
{
    if(par[ X ] == X) return X;
    else return find( par[ X ] );
}
void DFS(int u)
{
    int len = graph[ u ].size();
    for(int i = 0; i < len; i++)
    {
        int v = graph[ u ][ i ];
        if(mark[ v ])
        {
            mark[ v ] = false;
            gpr[ v ] = u;
            DFS( v );
        }
    }
}
void find_res(int s)
{
    if(gpr[ s ] == -1) return;
    else
    {
        int x = gpr[ s ];
        if(x == t) ifposi = true;
        maxr = maxr < wight[ s ][ x ] ? wight[ s ][ x ] : maxr;
        find_res( x );
    }
}
