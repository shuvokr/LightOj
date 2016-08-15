#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
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
#define fo(i, n) for(i = 1; i <= n; i++)
#define fa(i, n) for(i = 0; i < n - 1; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)
#define max 100000000000000+1

void input();

double save_res[1000001];

int main()
{
    int i;
    double tmp = 0;
    save_res[0] = 0.0;
    save_res[1] = 0.0;
    for(i = 2; i < 1000001; i++) {
        tmp += log10(i);
         save_res[i] = tmp;
    }

    input();

    return 0;
}
void input()
{
    LLD T, kag = 0, n, bag, i;
    double res;
    sf("%lld", &T);
    while(T--)
    {
        sf("%lld%lld", &n, &bag);
        res = 0;
        res = save_res[n] / log10(bag);
        //printf("%.5lf\n", save_res[n]);
        pf("Case %lld: %.0lf\n", ++kag, floor(res + 1.00));
    }
}

