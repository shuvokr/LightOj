/*
    Shuvo
    LOJ : 1006 name : Hex-a-bonacci
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define lu unsigned long int
#define llu unsigned long long int
#define lld long long int
#define sf scanf
#define pf printf
#define fo(i, n) for(i = 6; i <= n; i++)

void input();

int a, b, c, d, e, f, n;

int main()
{
    input();

    return 0;
}
void input()
{
    int kag = 0, T, i;
    sf("%d", &T);

    long long res[10001];

    while(T--)
    {
         sf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
         res[0] = a % 10000007; res[1] = b % 10000007; res[2] = c % 10000007; res[3] = d % 10000007; res[4] = e % 10000007; res[5] = f % 10000007;
         fo(i, n) res[i] = ((res[i-1] % 10000007) + (res[i-2] % 10000007) + (res[i-3] % 10000007) + (res[i-4] % 10000007) + (res[i-5] % 10000007) + (res[i-6] % 10000007)) % 10000007;
         printf("Case %d: %lld\n", ++kag, res[n] % 10000007);
    }
}
