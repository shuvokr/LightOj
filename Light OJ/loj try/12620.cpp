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

void input();

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, in[100000];
    in[ 0 ] = 0;
    in[ 1 ] = 1;
    for(i = 2; i < 200; i++)
    {
        in[ i ] = (in[i - 1] + in[i - 2]);
        if(in[i] > 99) in[i] %= 100;
        pf("%d\n", in[i]);
    }
    int a, b;
    sf("%d %d", &a, &b);
    a = 0;
    fo(i, b)
    {
        a += in[i];
    }
    pf("%d", a);
}
