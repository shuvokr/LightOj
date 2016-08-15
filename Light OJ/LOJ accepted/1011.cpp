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
#define maxn 16+1

#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
void reset();
int bit_mask(int i, int mask);

int satisfiction[ maxn ][ maxn ], n, res;
int dp[ maxn ][ 1 << 17 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j, kag = 0;
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &n); reset();
        fo(i, n) fo(j, n) sf("%d", &satisfiction[ i ][ j ]);
        pf("Case %d: %d\n", ++kag, bit_mask(0 , 0));
    }
}
void reset()
{
    mem(dp, -1);
    mem(satisfiction, 0);
}
int bit_mask(int i, int mask)
{
    if(i >= n) return 0;
    int& resu = dp[ i ][ mask ];
    if(resu != -1) return resu;
    resu = -1;
    for(int j = 0; j < n; j++)
    {
        if((mask & (1 << j)) == 0)
        {

            //dp[ i ][ j ] = bit_mask(i + 1, mask | (1 << j)) + satisfiction[ i ][ j ];
            resu = max(resu, bit_mask(i + 1, mask | (1 << j)) + satisfiction[ i ][ j ] );
            //resu = max(resu,  dp[ i ][ mask ]);
        }
    }
    return resu;
}
