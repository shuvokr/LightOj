#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define fo(i, n) for(i = 2; i < n; i++)
#define LLD long long

void save_res();
void input();
double calculat_res(long n);

double res[100001], tmp;

int main()
{
    memset(res, 0, 100001);
    save_res();
    input();

    return 0;
}
void save_res()
{
    int i, cou, k = 1, n = 100000001, siz = 1;

    tmp = 1.0;
    fo(i, n)
    {
        k++;
        tmp += double(1.0 / i);
        if(k == 1000)
        {
            res[siz++] = tmp;
            k = 0;
        }
    }
}
void input()
{
    double rs;
    long T, i, n, kag = 0;
    sf("%ld", &T);

    while(T--)
    {
        sf("%ld", &n);
        rs = calculat_res(n);
        pf("Case %ld: %.10lf\n", ++kag, rs);
    }
}
double calculat_res(long n)
{
    double sk, temp;
    long i, k;
    k = n / 1000;
    k *= 1000;
    if(k == n) return res[n / 1000];
    if(k < n)
    {
        temp = res[k / 1000];
        for(i = k + 1; i <= n; i++)
        {
            temp += double(1.0 / i);
        }
        return temp;
    }
    else
    {
        temp = res[1];
        for(i = 2; i <= n; i++)
        {
            temp += double(1.0 / i);
        }
        return temp;
    }
}
