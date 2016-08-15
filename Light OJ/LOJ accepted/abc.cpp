#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>



#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>


#define loop(i, n) for(int i=0; i<n; i++)
#define loopfrom1(i, n) for(int i=1; i<n; i++)
#define mem(array, value) memset(array, value, sizeof(array))
#define MIN(a, b) (a<b?a:b)
#define MAX(a, b) (a>b?a:b)
#define pb(a) push_back(a)
#define SZ size()
#define getint(n) scanf("%d", &n)
#define pi acos(-1.0)
#define inf 536870912         // 1<<29
#define debug cout<<"ok"<<endl
#define lld long long int

#define MAXX 200


using namespace std;



vector<int> Graph[MAXX];

char colormap[MAXX];
bool taken[MAXX];


int main()
{
    int step = 0;
    int v;
    bool flag;
    int number_of_nodes, edges;
    int first, second;
    while(getint(number_of_nodes))
    {
        if(number_of_nodes == 0)
        {
            break;
        }

        flag = true;
        loop(i, number_of_nodes)
        {
            Graph[i].clear();
        }


        mem(colormap, 0);
        mem(taken, 0);


        getint(edges);
        loop(i, edges)
        {
            getint(first);
            getint(second);
            Graph[first].pb(second);
            Graph[second].pb(first);
        }
        queue<int> Q;
        Q.push(0);
        colormap[0] = 1;
        while(! Q.empty())
        {
            int front = Q.front();
            int color = colormap[front];
            int toColor;
            if(color == 1)
            {
                toColor = 2;
            }
            else
            {
                toColor = 1;
            }
            loop(i, Graph[front].SZ)
            {
                v = Graph[front][i];
                if(colormap[v] == color)
                {
                    flag = false;
                    break;
                }
                else if(colormap[v]==0)
                {
                    Q.push(v);
                    colormap[v] = toColor;
                }
            }
            Q.pop();
        }

        if(flag)
        {
            printf("BICOLORABLE.\n");
        }
        else
        {
            printf("NOT BICOLORABLE.\n");
        }

    }
    return 0;
}
