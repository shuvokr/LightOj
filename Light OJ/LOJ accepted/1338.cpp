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
    int T, kag = 0, i, len, k;
    sf("%d", &T);
    getchar();
    char ch1[102], ch2[102];
    while(T--)
    {
        gets(ch1);
        gets(ch2);

        char sk1[102] = {0}, sk2[102] = {0};

        len = strlen(ch1);
        k = 0;
        fo(i, len) if(!isspace(ch1[i])) sk1[k++] = ch1[i];

        fo(i, k) if(islower(sk1[i])) sk1[i] = toupper(sk1[i]);
        sort(sk1, sk1 + k);

        len = strlen(ch2);
        k = 0;
        fo(i, len) if(!isspace(ch2[i])) sk2[k++] = ch2[i];

        fo(i, k) if(islower(sk2[i])) sk2[i] = toupper(sk2[i]);
        sort(sk2, sk2 + k);

        if(strcmp(sk1, sk2) == 0) pf("Case %d: Yes\n", ++kag);
        else pf("Case %d: No\n", ++kag);
    }
}
