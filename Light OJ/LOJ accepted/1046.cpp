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

void BFS(int i, int j);
bool isok(int i, int j);

int cost[ 12 ][ 12 ], tcost[ 12 ][ 12 ], mark[ 12 ][ 12 ];
char graph[ 12 ][ 12 ];
int row, col, move;
bool vis[ 10 ][ 10 ];

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
    int T, kag = 0, cou = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &row, &col);
        //getchar();
        cou = 0;
        //printf("%d %d\n", row, col);
        for(int i = 0; i < row; i++)
        {
            scanf("%s", graph[ i ]);
            for(int j = 0; j < col; j++)
            {
                tcost[ i ][ j ] = 0; mark[ i ][ j ] = 0;
                if(graph[ i ][ j ] != '.') cou++;
            }
        }

        //printf("%d %d\n", row, col);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(graph[ i ][ j ] != '.')
                {
                    move = graph[ i ][ j ] - 48;
                    CLR(cost, 0); CLR(vis, true); BFS(i, j);
                }
            }

       // printf("  %d %d\n", row, col);
        int minr = 1 << 29;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                //printf("*%d %d\n", mark[ i ][ j ], tcost[ i ][ j ]);
                if(mark[ i ][ j ] == cou)
                    minr = minr < tcost[ i ][ j ] ? minr : tcost[ i ][ j ];//printf("%d ", tcost[ i ][ j ]);

        if(cou == 0 || cou == 1) minr = 0;
        if(minr == 1 << 29) minr = -1;
        printf("Case %d: %d\n", ++kag, minr);
    }
}
void BFS(int i, int j)
{
    queue <int> Q;
    mark[ i ][ j ]++;
    Q.push( i ); Q.push( j );
    cost[ i ][ j ] = 0;
    vis[ i ][ j ] = false;
    while(!Q.empty())
    {
        i = Q.front(); Q.pop();
        j = Q.front(); Q.pop();
        for(int k = 0; k < 8; k++)
        {
            int u = i + horsed1[ k ];
            int v = j + horsed2[ k ];
            if(vis[ u ][ v ] && isok(u, v))
            {

                cost[ u ][ v ] = cost[ i ][ j ] + 1;
                int tmp = cost[ u ][ v ] / move;
                if(tmp * move != cost[ u ][ v ]) tmp++;
                tcost[ u ][ v ] += tmp;
                mark[ u ][ v ]++;
                vis[ u ][ v ] = false;
                Q.push( u ); Q.push( v );
            }
        }
    }
}
bool isok(int i, int j)
{
    if(i < 0 || j < 0 || i >= row || j >= col) return false;
    return true;
}
