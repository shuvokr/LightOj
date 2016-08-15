
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
#define CLR(n, v, x) memset(n, v, x)
#define INF 1 << 30
#define pb push_back
#define maxn 200+2
#define lim(v) v.begin(), v.end()
#define sz(v) ((int)v,size())
#define equals(a, b) (fabs(a-b)<eps)
#define pcase(n) printf("Case %d:\n", n);

#define white 0
#define black 1

const double PI = 2 * acos ( 0.0 );
const double eps = 1e-9;
const int MAX = 100005;

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
    long long sum;
    int lazy;
};

/**************All Function**************/

void init(int node, int b, int e);
void lazyreset(X &p);
void marge(X &root, X &left, X &right);
void update(int node, int b, int e);
void lazyupdate(X &p);
void calculate(X &p, int len);
void propagate(X &p, X &u, X &v);
void query(int node, int b, int e);

/****************************************/

int ar[ MAX ], n;
int x, y, val;
X ans, stree[ MAX * 4 ];
char com[ 4 ];

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
    int q, T, kag = 0; scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &n, &q);

        CLR(ar, 0, n+2);

        init(1, 0, n - 1);
        pcase( ++kag );
        while( q-- )
        {
            int tag; scanf("%d", &tag);
            if( tag )
            {
                scanf("%d %d", &x, &y);
                ans.sum = 0; query(1, 0, n - 1);
                printf("%lld\n", ans.sum);
            }
            else
            {
                scanf("%d %d %d", &x, &y, &val);
                update(1, 0, n - 1);
            }
        }
    }
}
void init(int node, int b, int e)
{
    lazyreset(stree[ node ]);

    if(b == e)
    {
        stree[ node ].sum = ar[ b ];
        return ;
    }
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    marge(stree[ node ], stree[ left ], stree[ right ]);
}
void lazyreset(X &p)
{
    p.lazy = 0;
}
void marge(X &root, X &left, X &right)
{
    root.sum = left.sum + right.sum;
}
void update(int node, int b, int e)
{
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    if(b > y || e < x)
    {
        calculate(stree[ node ], e - b + 1);
        if(b != e) propagate(stree[ node ], stree[ left ], stree[ right ]);
        lazyreset(stree[ node ]);
        return ;
    }

    if(b >= x && e <= y)
    {
        lazyupdate(stree[ node ]);
        calculate(stree[ node ], e - b + 1);
        //printf("%d ", stree[ node ]);
        if(b != e) propagate(stree[ node ], stree[ left ], stree[ right ]);
        lazyreset(stree[ node ]);
        return ;
    }

    propagate(stree[ node ], stree[ left ], stree[ right ]);
    lazyreset(stree[ node ]);

    update(left, b, mid);
    update(right, mid + 1, e);

    marge(stree[ node ], stree[ left ], stree[ right ]);
    //printf("%d ", stree[ node ]);
}
void lazyupdate(X &p)
{
    p.lazy += val;
}
void propagate(X &p, X &l, X &r)
{
    l.lazy += p.lazy;
    r.lazy += p.lazy;
}
void query(int node, int b, int e)
{
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    if(b > y || e < x)
    {
        calculate(stree[ node ], e - b + 1);
        if(b != e) propagate(stree[ node ], stree[ left ], stree[ right ]);
        lazyreset(stree[ node ]);
        return ;
    }

    if(b >= x && e <= y)
    {
        calculate(stree[ node ], e - b + 1);
        //printf("%d ", stree[ node ]);
        if(b != e) propagate(stree[ node ], stree[ left ], stree[ right ]);
        lazyreset(stree[ node ]);
        marge(ans, ans, stree[ node ]);
        //printf("       %d\n", ans.sum);
        //ans.sum += stree[ node ].sum;
        return ;
    }

    propagate(stree[ node ], stree[ left ], stree[ right ]);
    lazyreset(stree[ node ]);

    query(left, b, mid);
    query(right, mid + 1, e);

    marge(stree[ node ], stree[ left ], stree[ right ]);
    //printf("%d ", stree[ node ]);
}
void calculate(X &p, int len)
{
    p.sum = p.sum + p.lazy*len ;
}

