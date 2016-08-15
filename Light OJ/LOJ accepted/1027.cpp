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
#define lld long long
#define fo(i, n) for(i = 0; i < n; i++)
#define mem(m) memset(m, 0, sizeof(m))
void input();

int main()
{
    input();

    return 0;
}
void input()
{
    int cou, tot, T, n, in[101], kag = 0, mamo1, mamo2, i;
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &n);
        cou = 0, tot = 0;
        mem(in); fo(i, n) {sf("%d", &in[i]); if(in[i] < 0) cou++; tot += abs(in[i]);}
        pf("Case %d: ", ++kag);
        if(n == cou) {puts("inf"); continue;}
        mamo1 = tot;
        mamo2 = n - cou;
        int sk = 2;
        for(i = 2; i <= mamo2; i++)
        {
            while(mamo1 % i == 0 && mamo2 % i == 0) mamo1 /= i, mamo2 /= i;
        }
        pf("%d/%d\n", mamo1, mamo2);
    }
}
