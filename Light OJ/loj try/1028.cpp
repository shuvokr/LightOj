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

void procage();
void isprime();

long long i, kag, num, T, counter, prime[1000010];
bool ck[1000010];

int main()
{
    isprime();
    sf("%lld", &T), kag = 0;
    while(T--) procage();
    return 0;
}
void procage()
{
    long long count = 1;
    sf("%lld", &num);

    i = 0;
    for(i = 0; prime[i] * prime[i] <= num; i++)
    {
        counter = 1;
        if(num % prime[i] == 0)
        {
            while(num % prime[i] == 0 && num > 0) counter++, num /= prime[i];
            count *= counter;
        }
    }

    if(num > 1) count *= 2;
    pf("Case %lld: %lld\n", ++kag, count - 1);
}
void isprime()
{
    ck[0] = false; ck[1] = false;
    for(i = 2; i < 1000009; i++) ck[i] = true;

    int n = sqrt(1000009);
    for(i = 2; i <= n; i++)
        for(int j = i * i; j < 1000009; j += i)
            ck[j] = false;

    int k = 0;
    for(i = 2; i < 1000009; i++)
        if(ck[i])
            prime[k++] = i;
}

