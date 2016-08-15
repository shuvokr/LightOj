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
long long n, r, p, q, kag;

void procage();
int magic(long long n, long long p);

int main()
{
    long long T;
    sf("%lld", &T), kag = 0;
    while(T--) procage();
    return 0;
}

void procage()
{
    sf("%lld%lld%lld%lld", &n, &r, &p, &q);
    long long n2 = 0, n5 = 0, result;

    while(p % 2 == 0) p /= 2, n2++;
        n2 *= q;
    while(p % 5 == 0) p /= 5, n5++;
        n5 *= q;

    n2 += magic(n, 2) - magic(n - r, 2) - magic(r, 2);
    n5 += magic(n, 5) - magic(n - r, 5) - magic(r, 5);

    result = min(n2, n5);
    pf("Case %lld: %lld\n", ++kag, result);
}
int magic(long long n, long long p)
{
    long long res = 0;
    while(n) res += n / p, n /= p;

    return res;
}


