#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n) memset(n, 0, sizeof(n))
#define INF -1

#define white 1
#define red 2

typedef vector <int> vi;

void input();
int BFS(int index1, int index2);
bool boder_cheak(int x, int y);

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};

int row, col;
char graph[ 600 ][ 600 ];
bool mark[ 600 ][ 600 ];
int cost[ 600 ][ 600 ];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    input();

    return 0;
}
void input()
{
    int i, j, r, c, T, Qu, res, kag = 0;
    bool ss;
    sf("%d", &T);
    while(T--)
    {
        sf("%d %d %d", &row, &col, &Qu);
        getchar();
        fo(i, row) gets(graph[i]);
        ss = true;
        fo(i, row) fo(j, col) mark[ i ][ j ] = true, cost[ i ][ j ] = INF;
        fo(i, Qu)
        {
            sf("%d %d", &r, &c);
            if(ss)
            {
                pf("Case %d:\n", ++kag);
                ss = false;
            }
            if(mark[ r - 1 ][ c - 1 ])
            {
                pf("%d\n", BFS(r-1, c-1));
            }
            else pf("%d\n", cost[ r - 1 ][ c - 1 ]);
        }
    }
}
int BFS(int index1, int index2)
{
    int i, j, tmp1, tmp2, ans = 0;
    queue <int> Q;
    Q.push( index1 ); Q.push( index2 );
    mark[ index1 ][ index2 ] = false;

    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();
        fo(i, 4)
        {
            index1 = tmp1 + diraction1[ i ];
            index2 = tmp2 + diraction2[ i ];
            if(boder_cheak(index1, index2))
            if(mark[index1][index2] && graph[index1][index2] != '#')
            {
                mark[index1][index2] = false;
                if(graph[index1][index2] == 'C') ans++;
                Q.push(index1); Q.push(index2);
            }
        }
    }
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(cost[ i ][ j ] == INF && !mark[ i ][ j ]) cost[ i ][ j ] = ans;
        }
    }
    return ans;
}
bool boder_cheak(int x, int y)
{
    if(x == row || y == col || x < 0 || y < 0) return false;
    return true;
}
