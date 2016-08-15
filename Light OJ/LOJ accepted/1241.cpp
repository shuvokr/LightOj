#include <stdio.h>
int main()
{
    int i, T, kag = 0, n, tmp, max, shuvo, kr;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n); max = 2; kr = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if(max < tmp)
            {
                shuvo = tmp - max;
                kr += (shuvo / 5);
                kr += shuvo % 5 ? 1 : 0;
                max = tmp;
            }
        }
        printf("Case %d: %d\n", ++kag, kr);
    }
    return 0;
}
