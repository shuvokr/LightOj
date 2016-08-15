/***************** Shuvo *****************/
/****************** DIU *****************/

#pragma comment(linker, "/stack:64000000")

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define phl puts("Hello")
#define sf scanf
#define pf printf
#define si1(a) scanf("%d", &a)
#define si2(a, b) scanf("%d %d", &a, &b)
#define si3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define CLR(n, v) memset(n, v, sizeof( n ))

void Input();
void Sparse_Table_DP();
int query(int a, int b, int ind);

int ST[ 505 ][ 505 ][ 10 ], in[ 505 ][ 505 ], n, q;

int main()
{
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    Input();

    return 0;
    /// Not use cin/cout without necessity. This a causes of TLE :p
}
void Input()
{
	int T, kag = 0; si1( T );
	while( T-- )
	{
		si2(n, q);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) si1(in[ i ][ j ]);
		
		Sparse_Table_DP();
		pf("Case %d:\n", ++kag);
		while( q-- )
		{
			int a, b, c; si3(a, b, c);
			
			pf("%d\n", query(a - 1, b - 1, c));
		}
	}
}
void Sparse_Table_DP()
{
	CLR(ST, 0);
	for(int k = 0; (1 << k) <= n; k++)
		for(int i = 0; i + (1 << k) - 1 < n; i++)
			for(int j = 0; j + (1 << k) - 1 < n; j++)
			{
				if(k == 0) ST[ i ][ j ][ k ] = in[ i ][ j ];
				else 
				{
					int ind = 1 << (k - 1);
					ST[ i ][ j ][ k ] = max(ST[ i ][ j ][k - 1], max(ST[i + ind][ j ][k - 1], 
						max(ST[ i ][j + ind][k - 1], ST[i + ind][j + ind][k - 1])));
				}
			}
}
int query(int a, int b, int ind)
{
	int k = log2(ind);
	int id = 1 << k;
	return max(ST[ a ][ b ][ k ], max(ST[a + ind - id][ b ][ k ], 
		max(ST[ a ][b + ind - id][ k ], ST[a + ind - id][b + ind - id][ k ])));
}
