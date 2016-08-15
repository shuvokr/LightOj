#include <stdio.h>
using namespace std;
int main()
{
    int T, kag = 0;
    unsigned long long num, n, m, tmp;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%llu", &num);
        m = 4611686018427387904;
        while( true )
        {
            n = num / m;
            if(n * m == num)
            {
                printf("Case %d: %llu %llu\n", ++kag, n, m);
                break;
            }
            else m = m >> 1;
            if(m == 1)
            {
                printf("Case %d: Impossible\n", ++kag);
                break;
            }
        }
    }
    return 0;
}
