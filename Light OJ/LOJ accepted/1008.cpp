#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    long long i, k, cou, tmp, kag = 0, T, row, col, mask;
    scanf("%lld", &T);
    while( T-- )
    {
        scanf("%lld", &i);
        tmp = 1; k = 2;
        k = ceil(sqrt( i ));
        tmp = k * k;
        if(!( tmp % 2 ))
        {
            mask = tmp - k + 1;
            if(i <= tmp && i >= mask)
                printf("Case %lld: %lld %lld\n", ++kag, k, tmp - i + 1);
            else
                printf("Case %lld: %lld %lld\n", ++kag, k - (mask - 1 - i) - 1, k);
        }
        else
        {
            mask = tmp - k + 1;
            if(i <= tmp && i >= mask) printf("Case %lld: %lld %lld\n", ++kag, tmp - i + 1, k);
            else printf("Case %lld: %lld %lld\n", ++kag, k, k - (mask - 1 - i) - 1);
        }
    }
    return 0;
}
