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

void input();
int dp(int n);
int a, b, c, d, e, f, m;
int save_dp[10002];

int main()
{
    input();

    return 0;
}
void input()
{
    int T, kag = 0;
    sf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &m);
        int i; fo(i, 10002) save_dp[i] = -1;
        printf("Case %d: %d\n", ++kag, dp(m) % 10000007);
    }
}
int dp( int n )
{
    if( n == 0 ) return a;
    else if( n == 1 ) return b;
    else if( n == 2 ) return c;
    else if( n == 3 ) return d;
    else if( n == 4 ) return e;
    else if( n == 5 ) return f;
    else if(save_dp[n] != -1) return save_dp[n];
    else
    {
        save_dp[n] = ((dp(n-1) % 10000007) + (dp(n-2) % 10000007) + (dp(n-3) % 10000007) + (dp(n-4) % 10000007) + (dp(n-5) % 10000007) + (dp(n-6) % 10000007)) % 10000007 ;
        return save_dp[n];
    }
}
