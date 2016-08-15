#include <stdio.h>
using namespace std;
void binary(int n);
int cou, bin[ 100 ];
int main()
{
    int i, n, T, pos, kag = 0, tmp, j, k;
    int pow[ 32 ];
    pow[ 1 ] = 1;
    for(i = 2; i < 32; i++)
        pow[ i ] = pow[i - 1] + pow[i - 1];//, printf("%d %d\n", i, pow[ i ]);
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        cou = 1; binary( n );
        //for(int i = 1; i < cou; i++) printf("%d", bin[ i ]);
        for(i = 1; i < cou - 1; i++)
        {
            if(bin[ i ] && !bin[i + 1])
            {
                bin[ i ] = 0;
                bin[i + 1] = 1;
                break;
            }
        }
        if(i == cou - 1 && !bin[ 1 ])
        {
            bin[ cou++ ] = 1;
            bin[cou - 2] = 0;
            j = 1, k = cou - 3;
            while(j < k)
            {
                if(!bin[ j ] && bin[ k ])
                {
                    bin[ j ] = 1; bin[ k ] = 0;
                    j++; k--;
                }
                else if(bin[ j ] && bin[ k ]) j++, k--;
                else if(bin[ j ]) j++;
                else k--;
            }
        }
        tmp = pow[i + 1];
        if(pow[ i ] == n)
        {
            printf("Case %d: %d\n", ++kag, pow[i + 1]);
            continue;
        }
        if(tmp == n + 1)
        {
            printf("Case %d: %d\n", ++kag, n - pow[ i ] + tmp);
            continue;
        }
        j = 1, k = i - 1;
        while(j < k)
        {
            if(!bin[ j ] && bin[ k ])
            {
                bin[ j ] = 1; bin[ k ] = 0;
                j++; k--;
            }
            else if(bin[ j ] && bin[ k ]) j++, k--;
            else if(bin[ j ]) j++;
            else k--;
        }
        tmp = 0;
        for(i = 1; i < cou; i++)
            if(bin[ i ]) tmp += pow[ i ];
        printf("Case %d: %d\n", ++kag, tmp);
    }
    return 0;
}
void binary(int n)
{
    if(n < 2)
    {
        bin[ cou++ ] = n;
        return;
    }
    int ret;
    ret = n % 2;
    bin[ cou++ ] = ret;
    binary(n >> 1);
}
