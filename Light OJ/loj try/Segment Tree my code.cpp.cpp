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
struct tree
{
    long long lazy, sum;
};

void update(int node, int b, int e, int x, int y, long long  val);
void lazy_update(tree &root, int val);
void calculate(tree &root, int val, int len);
void lazy_reset(tree &root);
void query(int node, int b, int e, int x, int y);
void marge(tree &root, tree L, tree R);

tree stree[ 400005 ], ans;
int n, q;

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
    int T, kag = 0, tag, x, y, val;
    sf("%d", &T);
    while( T-- )
    {
        CLR(stree, 0);
        sf("%d %d", &n, &q);
        pf("Case %d:\n", ++kag);
        while( q-- )
        {
            sf("%d", &tag);
            if(tag == 0)
            {
                sf("%d %d %d", &x, &y, &val);
                update(1, 0, n - 1, x, y, val);
            }
            else
            {
                sf("%d %d", &x, &y);
                ans.sum = 0;
                query(1, 0, n - 1, x, y);
                pf("%lld\n", ans.sum);
            }
        }
    }
}
void update(int node, int b, int e, int x, int y, long long val)
{
    if(e < x || b > y) return;
    if(b >= x && e <= y)
    {
        lazy_update(stree[ node ], val);
        calculate(stree[ node ], val, e - b + 1);
        return;
    }

    int left_child = node << 1, right_child = left_child + 1, mid = (b + e) >> 1;

    if(stree[ node ].lazy != 0)
    {
        update(left_child, b, mid, b, mid, stree[ node ].lazy);
        update(right_child, mid + 1, e, mid + 1, e, stree[ node ].lazy);
        lazy_reset( stree[ node ] );
    }

    update(left_child, b, mid, x, y, val);
    update(right_child, mid + 1, e, x, y, val);

    marge(stree[ node ], stree[ left_child ], stree[ right_child ]);
}
void lazy_update(tree &root, int val)
{
    root.lazy += val;
}
void calculate(tree &root, int val, int len)
{
    root.sum += val * len;
}
void lazy_reset(tree &root)
{
    root.lazy = 0;
}
void query(int node, int b, int e, int x, int y)
{
    if(b > y || e < x) return;

    int left_child = node << 1, right_child = left_child + 1, mid = (b + e) >> 1;

    if(b >= x && e <= y)
    {
        //calculate(stree[ node ], stree[ node ].lazy, e - b + 1);
        ans.sum += stree[ node ].sum;
        return;
    }

    if(stree[ node ].lazy != 0)
    {
        update(left_child, b, mid, b, mid, stree[ node ].lazy);
        update(right_child, mid + 1, e, mid + 1, e, stree[ node ].lazy);
        lazy_reset( stree[ node ] );
    }

    query(left_child, b, mid, x, y);
    query(right_child, mid + 1, e, x, y);
}
void marge(tree &root, tree L, tree R)
{
    root.sum = L.sum + R.sum;
}
