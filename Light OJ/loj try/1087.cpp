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
#include <deque>
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
template <class T> T power ( T a, T p ) { T res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
template <class T> T cordinatlenth(T a, T b, T c, T d) { return sqrt( sq(a - c) + sq(b - d) ); }
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
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

/*
#define M 1000005
int phi[M];

void calculatePhi()
{
    for (int i = 1; i < M; i++) phi[i] = i;
    for (int p = 2; p < M; p++)
        if (phi[p] == p) // p is a prime
            for (int k = p; k < M; k += p) phi[k] -= phi[k] / p;
}
*/

/*
const int pr = 500001;
int prime[ 41539 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i * i; j < pr; j += i + i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) ind++; printf("%d\n", ind);
}
*/

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

#define check(n, pos) (n & (1<<(pos)))
#define biton(n, pos) (n | (1<<(pos)))
#define bitoff(n, pos) (n & ~(1<<(pos)))

void input();

/**************************Templet end*********************************/

struct TREE
{
    int sum, val;
};

void init(int node, int b, int e);
void update(int node, int b, int e, int x, int val);
void query(int node, int b, int e, int x);

TREE stree[ 600010 ];
int n, in[ 150010 ], res;

int main()
{
    #ifdef monkey
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    input();

    return 0;
}
void input()
{
    int Q, T, kag = 0;
    sf("%d", &T);
    while( T-- )
    {
        sf("%d %d", &n, &Q);
        for(int i = 1; i <= n; i++) sf("%d", &in[ i ]);
        CLR(stree, 0);

        int ck = n, p = n;
        n = n + Q;

        init(1, 1, n);

        pf("Case %d:\n", ++kag);

        while( Q-- )
        {
            char tag[ 3 ];
            sf("%s", tag);
            if(tag[ 0 ] == 'c')
            {
                int x; sf("%d", &x);

                if(x > ck)
                {
                    puts("none");
                    continue;
                }
                ck--;

                query(1, 1, n, x);
                pf("%d\n", res);
            }
            else
            {
                int x; sf("%d", &x); ck++; p++;
                //in[ n ] = x;
                update(1, 1, n, p, x);
            }
        }
    }
}
void init(int node, int b, int e)
{
    if(b == e)
    {
        stree[ node ].val = in[ b ];
        stree[ node ].sum = 1;
        //pf("**%d %d %d\n", b, e, stree[ node ].sum);
        return;
    }

    int left_child = node << 1, right_child = left_child + 1, mid = (b + e) >> 1;

    init(left_child, b, mid);
    init(right_child, mid + 1, e);

    stree[ node ].sum = stree[ left_child ].sum + stree[ right_child ].sum;
}
void update(int node, int b, int e, int x, int val)
{
    if(b > x || e < x) return;

    if(b >= x && e <= x)
    {
        stree[ node ].val = val;
        stree[ node ].sum = 1;
        //pf("**%d %d %d\n", b, e, stree[ node ].sum);
        return;
    }

    int left_child = node << 1, right_child = left_child + 1, mid = (b + e) >> 1;

    update(left_child, b, mid, x, val);
    update(right_child, mid + 1, e, x, val);

    stree[ node ].sum = stree[ left_child ].sum + stree[ right_child ].sum;
    //pf("*%d %d %d %d %d\n", b, e, stree[ node ].sum, stree[left_child].sum, stree[right_child].sum);
}
void query(int node, int b, int e, int x)
{
    if(stree[node].sum < x) return;
    if(b == e)
    {
        res = stree[ node ].val;
        stree[node].sum = 0;
        //pf("**   %d %d %d\n", b, e, stree[ node ].sum);
        return;
    }

    int left_child = node << 1, right_child = left_child + 1, mid = (b + e) >> 1;

    if(x <= stree[left_child].sum) query(left_child, b, mid, x);
    else query(right_child, mid + 1, e, x - stree[left_child].sum);

    stree[ node ].sum = stree[ left_child ].sum + stree[ right_child ].sum;
}
