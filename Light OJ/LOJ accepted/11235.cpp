
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
const int MAX = 100010;

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


int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

struct X
{
    int maxval, lf, rg;
};

void init(int node, int b, int e);
void marge(X &root, X &l, X &r);
void query(int node, int b, int e);
void res(X root, int ans);

X stree[ MAX * 4 ], ans;
int in[ MAX ], an, x, y;

int main()
{
    //#ifdef localhost
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    int n, q, val, tmp;
    while(~scanf("%d", &n) && n)
    {
        scanf("%d", &q);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &in[ i ]);
        }

        init(1, 0, n - 1);

        while( q-- )
        {
            scanf("%d %d", &x, &y); x--; y--;
            an = -1;
            ans.lf = ans.maxval = ans.rg = 0;
            query(1, 0, n - 1);
            printf("%d %d\n", ans.maxval, an);
        }
    }
}
void init(int node, int b, int e)
{
    if(b == e)
    {
        stree[ node ].lf = stree[ node ].rg = in[ b ];
        stree[ node ].maxval = 1;
        return ;
    }

    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    marge(stree[ node ], stree[ left ], stree[ right ]);
}
void marge(X &root, X &l, X &r)
{
    if(l.rg == r.lf)
    {
        root.maxval = l.maxval + r.maxval
    }
    else root.maxval = max(l.maxval, r.maxval);
    root.lf = l.lf;
    root.rg = r.lf;
}
void query(int node, int b, int e)
{
    if(b > y || e < x)
    {
        return;
    }
    if(b >= x && e <= y)
    {
        //printf("  %d %d\n", b, e);
        res(stree[ node ], an);
        marge(ans, ans, stree[ node ]);
        return ;
    }

    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    query(left, b, mid);
    query(right, mid + 1, e);
}
void res(X root, int ans)
{
    an += root.maxval;
    //printf("%d ", an);
}
