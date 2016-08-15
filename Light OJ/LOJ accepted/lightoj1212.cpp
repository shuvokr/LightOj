#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define NIL -1

int main()
{
    list <int> lst;
    char ch[30], c[20];
    int z = 0, temp, tp, i, j, n, m, cou = 0, len, T;
    sf("%d", &T);
    while(T--)
    {
        bool ck = true;
        lst.clear();
        cou = 0;
        sf("%d%d", &n, &m);
        getchar();
        while(m--)
        {
            memset(ch, 0, sizeof(ch));
            memset(c, 0, sizeof(c));
            gets(ch);
            if(ck) pf("Case %d:\n", ++z), ck = false;
            len = strlen(ch);
            if(len > 8)
            {
                sscanf(ch, "%s%d", c, &temp);
                if(strcmp(c, "pushLeft") == 0)
                {
                    cou++;
                    if(cou > n) puts("The queue is full"), cou--;
                    else
                    {
                        lst.push_front(temp);
                        pf("Pushed in left: %d\n", temp);
                    }
                }
                else
                {
                    cou++;
                    if(cou > n) puts("The queue is full"), cou--;
                    else
                    {
                        lst.push_back(temp);
                        pf("Pushed in right: %d\n", temp);
                    }
                }
            }
            else
            {
                cou--;
                if(cou < 0) cou = 0;
                if(strcmp(ch, "popLeft") == 0)
                {
                    if(lst.empty()) puts("The queue is empty");
                    else
                    {
                        temp = lst.front();
                        lst.pop_front();
                        pf("Popped from left: %d\n", temp);
                    }
                }
                else
                {
                    if(lst.empty()) puts("The queue is empty");
                    else
                    {
                        temp = lst.back();
                        lst.pop_back();
                        pf("Popped from right: %d\n", temp);
                    }
                }
            }
        }
    }
    return 0;
}
