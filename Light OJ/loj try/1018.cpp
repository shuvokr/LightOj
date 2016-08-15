#pragma comment(linker, "/stack:64000000")
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

struct point
{
    int x, y;
}in[ 20 ];

int DP(int mask, int flag);
bool isokr(int x, int y);
bool isokc(int x, int y);
bool isokd(int x, int y);

int mark[ 2010 ][ 2010 ], n, mamo[1 << 16][ 3 ];

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
    int T, kag = 0;
    sf("%d", &T);
    while( T-- )
    {
        sf("%d", &n);
        CLR(mark, 0);
        for(int i = 0; i < n; i++)
        {
            sf("%d %d", &in[i].x, &in[i].y);
            in[i].x += 1000;
            in[i].y += 1000;
        }
        CLR(mamo, -1);
        pf("Case %d: %d\n", ++kag, DP(0, 0) - 1);
    }
}
int DP(int mask, int flag)
{
    if(mask == (1 << n) - 1)pf("%d ", mask);
    if(mask == (1 << n) - 1) return 0;
    int &ret = mamo[ mask ][ flag ];
    if(ret != -1) return ret;
    int a = 0, b = 0, c = 0; ret = 0;

    for(int i = 0; i < n; i++)
    {
        if(check(mask, i)) continue;

        int cou = isokc(in[i].x, in[i].y) ? 1 : 0;
        mark[ in[i].x ][ in[i].y ] = 1;
        //pf("*%d ", cou);
        a = cou + DP(biton(mask, i), 0);
        mark[ in[i].x ][ in[i].y ] = 0;

        cou = isokr(in[i].x, in[i].y) ? 1 : 0;
        mark[ in[i].x ][ in[i].y ] = 1;
        b = cou + DP(biton(mask, i), 1);
        mark[ in[i].x ][ in[i].y ] = 0;

        cou = isokd(in[i].x, in[i].y) ? 1 : 0;
        //pf("*%d ", cou);
        mark[ in[i].x ][ in[i].y ] = 1;
        b = cou + DP(biton(mask, i), 2);
        mark[ in[i].x ][ in[i].y ] = 0;

        //pf("**%d ", cou);
    }
    ret = INF;
    if( a ) ret = min(ret, a);
    if( b ) ret = min(ret, b);
    if( c ) ret = min(ret, c);
    //ret = min(c, min(a, b));
    return ret;
}
bool isokc(int x, int y)
{
    int a = x, b = y + 1;
    while(b < 2001)
    {
        if(mark[ a ][ b ]) return false;
        b++;
    }
    b = y - 1;
    while(b > -1)
    {
        if(mark[ a ][ b ]) return false;
        b--;
    }
    return true;
}
bool isokr(int x, int y)
{
    int a = x + 1, b = y;
    while(a < 2001)
    {
        if(mark[ a ][ b ]) return false;
        a++;
    }
    a =  x - 1;
    while(a > -1)
    {
        if(mark[ a ][ b ]) return false;
        a--;
    }
    return true;
}
bool isokd(int x, int y)
{
    int a = x, b = y;
    while(a < 2001 && b < 2001)
    {
        if(mark[ a ][ b ]) return false;
        a++; b++;
    }
    a =  x; b = y;
    while(a > -1 && b > -1)
    {
        if(mark[ a ][ b ]) return false;
        a--; b--;
    }
    return true;
}
