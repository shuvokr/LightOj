#include <stdio.h>
using namespace std;
int main()
{
    int T, kag = 0, a, b;
    long res, m, n;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%ld %ld", &m, &n);
        m = n - m;
        a = (n * (n+1) >> 1) % 3 ? 0 : 1;
        b = ((n - 1) * n >> 1) % 3 ? 0 : 1;
        if(!(m % 3)) res = (m << 1) / 3 + a;
        else if(m % 3 == 1) res = ((m - 1) << 1) / 3 + a + b;
        else res = ((m - 2) << 1) / 3 + 2;
        printf("Case %d: %ld\n", ++kag, res);
    }
    return 0;
}
