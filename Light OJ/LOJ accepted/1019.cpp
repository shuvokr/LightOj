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

#define maxn 100000+10
#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 1; i <= n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 1e9

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

template <class T>
class Heap
{
    T pq[ maxn ];
    int index;

    void big_top(int pos)
    {
        int parent = pos / 2;
        if(parent < 1) return;
        if(pq[ parent ] < pq[ pos ])
        {
            swap(pq[ pos ], pq[ parent ]);
            big_top( pos );
        }
    }
    void sink(int pos)
    {
        int left = pos * 2, right = left + 1;
        if(right > index) return;
        if(right < index)
        {
            if(pq[ pos ] < pq[ left ])
            {
                swap(pq[ pos ], pq[ left ]);
                sink( left );
            }
            else if(pq[ pos ] < pq[ right ])
            {
                swap(pq[ pos ], pq[ right ]);
                sink( right );
            }
        }
    }
    public:
    Heap() {index = 1;}
    void push(T n)
    {
        pq[ index ] = n;
        big_top( index );
        index++;
    }
    T top() {return pq[ 1 ];}
    void pop()
    {
        pq[ 1 ] = pq[ --index ];
        sink( 1 );
    }
    bool empty() {return (index == 1);}
};

struct node
{
    int nd, wi;
    node() {}
    node(int a, int w):nd(a), wi(w) {}
    bool operator<(const node &x) const
    {
        return (wi < x.wi);
    }
};

int row_col, edge;
vector <vpi> graph;
vi cost;

void input();
void Dijkstra();

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j, kag = 0, tmp, u, v, w;
    bool ck;
    sf("%d", &T);
    while(T--)
    {
        sf("%d %d", &row_col, &edge);
        graph.assign(row_col + 1, vpi());
        ck = false;
        while(edge--)
        {
            sf("%d %d %d", &u, &v, &w);
            if(u == row_col || v == row_col) ck = true;
            graph[ u ].push_back(pii(v, w));
            graph[ v ].push_back(pii(u, w));
        }
        pf("Case %d: ", ++kag);
        if(!ck)
        {
            puts("Impossible");
        }
        else
        {
            Dijkstra();
            if(cost[ row_col ] == INF) puts("Impossible");
            else pf("%d\n", cost[ row_col ]);
        }
    }
}
void Dijkstra()
{
    cost.assign(row_col + 1, INF);
    int i, sorce = 1, nod, wit;
    Heap <node> Q;
    cost[ sorce ] = 0;
    node sk;
    Q.push(node(sorce, 0));

    while(!Q.empty())
    {
        sk = Q.top();
        Q.pop();
        nod = sk.nd;
        wit = sk.wi;
        if(wit == cost[ nod ])
        {
           for(i = 0; i < graph[ nod ].size(); i++)
           {
                pii pr = graph[ nod ][ i ];
                //pf("%d %d %d\n", nod, pr.first, pr.second); //This line print Garbag, but why ???
                if(cost[ nod ] + pr.second < cost[ pr.first ])
                {
                    cost[ pr.first ] = cost[ nod ] + pr.second;
                    Q.push(node(pr.first, cost[ pr.first ]));
                }
           }
        }
    }
}

