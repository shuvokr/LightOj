#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    LLD n, T, tmp, res, kag = 0;
    char ch[7];
    sf("%lld", &T);
    while(T--)
    {
        sf("%lld", &n);
        res = 0;
        pf("Case %lld:\n", ++kag);
        while(n--)
        {
            sf("%s", ch);
            if(ch[0] == 'd')
            {
                sf("%lld", &tmp);
                res += tmp;
                continue;
            }
            pf("%lld\n", res);
        }
    }
}
