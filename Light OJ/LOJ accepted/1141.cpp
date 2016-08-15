#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>

using namespace std;

int BFS();

const int pr = 1001;
int cost[ 1001 ], s, target;
int prime[ 170 ], ind;
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
        if(mark[ i ]) prime [ ind++ ] = i; //printf("%d\n", ind);
}

int  main()
{
    primelist();
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &s, &target);
        memset(cost, -1, sizeof cost);
        printf("Case %d: %d\n", ++kag, BFS());
    }
    return 0;
}
int BFS()
{
    cost[ s ] = 0;
    queue <int> q;
    q.push( s );
    while( !q.empty() )
    {
        int node = q.front(); q.pop();
        for(int i = 0; prime[ i ] < node; i++)
        {
            if(node % prime[ i ] == 0 && node + prime[ i ] <= target && cost[ node + prime[ i ] ] == -1)
            {
                cost[node + prime[ i ]] = cost[ node ] + 1;
                if(node + prime[ i ] == target) while(!q.empty()) q.pop();
                else q.push(node + prime[ i ]);
            }
        }
    }
    return cost[ target ];
}
