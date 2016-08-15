/*
                                    Shuvo
                                    Loj 1077
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

#define sf scanf
#define pf printf

long long GCD(long long a,long long b);

int main()
{
    long long T, a, b, c, d, res, kag = 0;
    sf ("%lld", &T);
    while(T--)
    {
        sf("%lld %lld %lld %lld", &a, &b, &c, &d);
        a =abs(a - c);
        b = abs(b - d);
        if(a == 0) pf("Case %lld: %lld\n",++kag, b+1);
        else if(b == 0) pf("Case %lld: %lld\n",++kag, a+1);
        else
        {
            res = GCD(a, b) + 1;
            pf("Case %lld: %lld\n",++kag, res);
        }
    }
    return 0;
}

long long GCD(long long a,long long b)
{
    long long c;
    if(a > b)
    {
        while(b != 0)
        {
            c = b;
            b = a % b;
            a = c;
        }
    }
    else
    {
        while(a != 0)
        {
            c = a;
            a = b % a;
            b = c;
        }
    }
    return c;
}

