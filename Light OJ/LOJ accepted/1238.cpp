#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define lu unsigned long int
#define llu unsigned long long int
#define lld long long int
#define sf scanf
#define pf printf
#define fo(i, n) for(i = 0; i < n; i++)
#define mem(n) memset(n, -1, sizeof(n))

void input();
void BFS(int index1, int index2);
bool boundary_cheak(int i, int j);

char in[ 22 ][ 22 ];
int diraction1[] = {-1, 0, 1, 0};
int diraction2[] = {0, 1, 0, -1};
int cost[ 22 ][ 22 ], row, col, cou;

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, max = 0, kag = 0, T;
    bool ck;
    sf("%d", &T);
    while(T--)
    {
        max = 0;
        sf("%d %d", &row, &col);
        getchar(); mem(in);
        fo(i, row) gets(in[ i ]);

        ck = false;
        fo(i, row)
        {
            fo(j, col)
            {
                if(in[ i ][ j ] == 'h')
                {
                    BFS(i, j);
                    ck = true;
                }
                if(ck) break;
            }
            if(ck) break;
        }

        max = -1;
        fo(i, row)
        {
            fo(j , col)
            {
                if(max < cost[ i ][ j ]) max = cost[ i ][ j ];
            }

        }
        pf("Case %d: %d\n", ++kag, max);
    }
}
void BFS(int index1, int index2)
{
    int tmp1, tmp2, i, j, res, cou = 0;
    queue < int > Q;
    mem(cost);
    Q.push( index1 ); Q.push( index2 );
    cost[ index1 ][ index2 ] = 0;
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();
        fo(i, 4)
        {
            index1 = tmp1 + diraction1[ i ];
            index2 = tmp2 + diraction2[ i ];

            if(boundary_cheak(index1, index2))
            if(in[ index1 ][ index2 ] == '.')
            {
                in[ index1 ][ index2 ] = '#';
                if(cost[ index1 ][ index2 ] == -1)
                    cost[ index1 ][ index2 ] = cost[ tmp1 ][ tmp2 ] + 1;
                Q.push( index1 ); Q.push( index2 );
            }
            else if(in[ index1 ][ index2 ] == 'a' || in[ index1 ][ index2 ] == 'b' || in[ index1 ][ index2 ] == 'c')
            {
                cou++;
                in[ index1 ][ index2 ] = '#';
                cost[ index1 ][ index2 ] = cost[ tmp1 ][ tmp2 ] + 1;
                Q.push( index1 ); Q.push( index2 );
                if(cou == 3) break;
            }
            if(cou == 3) break;
        }
        if(cou == 3) break;
    }
}
bool boundary_cheak(int i, int j)
{
    if(i == row || i < 0) return false;
    if(j == col || j < 0) return false;
    return true;
}

