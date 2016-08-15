#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int BFS(int s, int e);

typedef vector<int> vi;
vector <vi> graph;
int cost[ 20001 ];
bool vis[ 20001 ];

int main()
{
    //freopen("output.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    graph.assign(20000, vi());
    map <string, int> mp;
    map <int, string> m;
    m.clear();
    mp.clear();
    int ind = 1;
    int a = 'a', b = 'z' + 1;
    for(int i = a; i < b; i++)
    {
        for(int j = a; j < b; j++)
        {
            int last;
            bool first = true;
            char in[ 5 ]; in[ 3 ] = NULL;
            for(int k = a; k < b; k++)
            {
                int p, pp;
                in[0] = i; in[1] = j; in[2] = k;
                if(mp[ in ] == 0)
                {
                    mp[ in ] = ind;
                    m[ ind ] = in;
                    p = ind++;
                }
                else p = mp[ in ];

                int x = i + 1, y = j, z = k;
                if(x == 123) x = 'a';
                in[0] = x; in[1] = y; in[2] = z;
                if(mp[ in ] == 0)
                {
                    mp[ in ] = ind;
                    m[ ind ] = in;
                    pp = ind++;
                }
                else pp = mp[ in ];
                graph[p].push_back( pp );
                graph[pp].push_back( p );

                x = i - 1, y = j, z = k;
                if(x == 96) x = 'z';
                in[0] = x; in[1] = y; in[2] = z;
                if(mp[ in ] == 0)
                {
                    mp[ in ] = ind;
                    m[ ind ] = in;
                    pp = ind++;
                }
                else pp = mp[ in ];
                graph[p].push_back( pp );
                graph[pp].push_back( p );

                x = i, y = j + 1, z = k;
                if(y == 123) y = 'a';
                in[0] = x; in[1] = y; in[2] = z;
                if(mp[ in ] == 0)
                {
                    mp[ in ] = ind;
                    m[ ind ] = in;
                    pp = ind++;
                }
                else pp = mp[ in ];
                graph[p].push_back( pp );
                graph[pp].push_back( p );

                x = i, y = j - 1, z = k;
                if(x == 96) y = 'z';
                in[0] = x; in[1] = y; in[2] = z;
                if(mp[ in ] == 0)
                {
                    mp[ in ] = ind;
                    m[ ind ] = in;
                    pp = ind++;
                }
                else pp = mp[ in ];
                graph[p].push_back( pp );
                graph[pp].push_back( p );

                x = i, y = j, z = k + 1;
                if(z == 123) z = 'a';
                in[0] = x; in[1] = y; in[2] = z;
                if(mp[ in ] == 0)
                {
                    mp[ in ] = ind;
                    m[ ind ] = in;
                    pp = ind++;
                }
                else pp = mp[ in ];
                graph[p].push_back( pp );
                graph[pp].push_back( p );

                x = i, y = j, z = k - 1;
                if(z == 96) z = 'z';
                in[0] = x; in[1] = y; in[2] = z;
                if(mp[ in ] == 0)
                {
                    mp[ in ] = ind;
                    m[ ind ] = in;
                    pp = ind++;
                }
                else pp = mp[ in ];
                graph[p].push_back( pp );
                graph[pp].push_back( p );
            }
        }
    }

    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        string a, b;
        cin >> a >> b;
        int s = mp[ a ], ee = mp[ b ];
        //mp >> str, int
        //m >>> int, str
        int n;
        scanf("%d", &n);
        string c, d, e;
        char t[ 5 ];
        memset(vis, true, sizeof vis);
        bool ck = true;
        for(int ii = 0; ii < n; ii++)
        {
            cin >> c >> d >> e;
            //cout << c << " " << d << " " << e << endl;
            for(int i = 0; i < c.size(); i++)
            {
                t[0] = c[i];
                for(int j = 0; j < d.size(); j++)
                {
                    //puts("ok");
                    t[1] = d[j];
                    for(int k = 0; k < e.size(); k++)
                    {
                        t[2] = e[k];
                        //puts("ok");
                        //cout << t << endl;
                        if(t == a || t == b) ck = false;
                        vis[ mp[t] ] = false;
                    }
                }
            }
        }
        if(!vis[ s ] || !ck)
        {
            printf("Case %d: -1\n", ++kag);
            continue;
        }
        for(int i = 0; i < 20000; i++) cost[ i ] = 1 << 29;
        int res = BFS(s, ee);
        if(res == 1 << 29) printf("Case %d: -1\n", ++kag);
        else printf("Case %d: %d\n", ++kag, res);
    }
    return 0;
}
int BFS(int s, int e)
{
    cost[ s ] = 0;
    vis[ s ] = false;
    queue <int> Q;
    Q.push( s );
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        for(int i = 0; i < graph[ u ].size(); i++)
        {
            int v = graph[ u ][ i ];
            if(vis[ v ])
            {
                vis[ v ] = false;
                cost[ v ] = cost[ u ] + 1;
                Q.push( v );
            }
        }
    }
    return cost[ e ];
}

