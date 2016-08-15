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
#define fa(i, n) for(i = 0; i < n - 1; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)
#define max 100000000000000+1

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    LLD k, d1, d2, d3, d4, b1, b2, b3, b4, tmp, T, mamo[] = {128, 64, 32, 16, 8, 4, 2, 1}, res, kag = 0;
    bool ck;
    sf("%lld", &T);

    while(T--)
    {
        sf("%lld.%lld.%lld.%lld%lld.%lld.%lld.%lld", &d1, &d2, &d3, &d4, &b1, &b2, &b3, &b4);

        res = 0;
        k = 7;
        while(b1 != 0)
        {
            tmp = b1 % 10;
            b1 /= 10;
            if(tmp == 1) res += mamo[k];
            k--;
        }
        if(res != d1)
        {
            pf("Case %lld: No\n", ++kag);
            continue;
        }

        res = 0;
        k = 7;
        while(b2 != 0)
        {
            tmp = b2 % 10;
            b2 /= 10;
            if(tmp == 1) res += mamo[k];
            k--;
        }
        if(res != d2)
        {
            pf("Case %lld: No\n", ++kag);
            continue;
        }

        res = 0;
        k = 7;
        while(b3 != 0)
        {
            tmp = b3 % 10;
            b3 /= 10;
            if(tmp == 1) res += mamo[k];
            k--;
        }
        if(res != d3)
        {
            pf("Case %lld: No\n", ++kag);
            continue;
        }

        res = 0;
        k = 7;
        while(b4 != 0)
        {
            tmp = b4 % 10;
            b4 /= 10;
            if(tmp == 1) res += mamo[k];
            k--;
        }
        if(res != d4)
        {
            pf("Case %lld: No\n", ++kag);
            continue;
        }

        pf("Case %lld: Yes\n", ++kag);
    }
}
