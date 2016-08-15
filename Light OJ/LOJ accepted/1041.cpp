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
}in[ 60 ];

bool cmp(const data &x, const data &y)
{
    if(x.cost < y.cost) return true;
    return false;
}

void DFS(int u);
int find(int u);

vector <vi> graph;
map <string, int> ci;
map <int, string> ic;

int par[ 110 ], node;
bool mark[ 110 ];

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
    int T, n, ct, kag = 0;
    string a, b;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n); node = 1;
        ci.clear(); ic.clear();
        graph.assign(60, vi());
        for(int i = 0, x, y; i < n; i++)
        {
            cin >> a >> b >> ct;
            if(ci[ a ] == 0)
            {
                ci[ a ] = node;
                ic[ node ] = a;
                x = node++;
            }
            else x = ci[ a ];

            if(ci[ b ] == 0)
            {
                ci[ b ] = node;
                ic[ node ] = b;
                y = node++;
            }
            else y = ci[ b ];

            graph[ x ].pb( y );
            graph[ y ].pb( x );

            in[ i ].u = x; in[ i ].v = y; in[ i ].cost = ct;
        }
        CLR(mark, true);
        DFS( 1 ); bool impo = false;
        for(int i = 1; i < node; i++)
            if(mark[ i ]) impo = true;
        printf("Case %d: ", ++kag);
        if( impo )
        {
            puts("Impossible");
            continue;
        }
        sort(in, in + n, cmp);
        int res = 0;
        for(int i = 1; i < node; i++) par[ i ] = i;
        for(int i = 0; i < n; i++)
        {
            int a = find( in[i].u ), b = find( in[ i ].v );
            if(a != b)
            {
                par[ b ] = a;
                res += in[ i ].cost;
            }
        }
        printf("%d\n", res);
    }
}
void DFS(int u)
{
    mark[ u ] = false;
    int len = graph[ u ].size();
    for(int i = 0; i < len; i++)
    {
        int v = graph[ u ][ i ];
        if(mark[ v ]) DFS( v );
    }
}
int find(int u)
{
    if(par[ u ] == u) return u;
    else return find(par[ u ]);
}
