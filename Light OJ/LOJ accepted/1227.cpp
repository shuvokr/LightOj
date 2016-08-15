#include <stdio.h>
int main()
{
    int tmp, i, n, p, q, res, T, kag = 0, dim, ojon;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d %d", &n, &p, &q);
        dim = ojon = res = 0;
        p++; q++;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            dim++; ojon += tmp;
            res += dim < p && ojon < q ? 1 : 0;
        }
        printf("Case %d: %d\n", ++kag, res);
    }
    return 0;
}
