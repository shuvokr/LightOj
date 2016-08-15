#include <stdio.h>
using namespace std;
int main()
{
    int tmp, T, kag = 0, res, row, col;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &row, &col);
        if(row == 1)
        {
            printf("Case %d: %d\n", ++kag, col);
            continue;
        }
        if(col == 1)
        {
            printf("Case %d: %d\n", ++kag, row);
            continue;
        }
        if(row < 3 && col < 3) {printf("Case %d: %d\n", ++kag, row * col); continue;}
        if(row == 2)
        {
            tmp = (col + 1) / 2;
            if(tmp % 2 == 0)
            {
                printf("Case %d: %d\n", ++kag, (tmp / 2) * 4);
                continue;
            }
            else
            {
                if(col % 2 == 0)
                {
                    printf("Case %d: %d\n", ++kag, ((tmp+1) / 2) * 4);
                    continue;
                }
                else
                {
                    printf("Case %d: %d\n", ++kag, (((tmp+1) / 2) * 4) - 2);
                    continue;
                }
            }
        }
        if(col == 2)
        {
            tmp = (row + 1) / 2;
            if(tmp % 2 == 0)
            {
                printf("Case %d: %d\n", ++kag, (tmp / 2) * 4);
                continue;
            }
            else
            {
                if(row % 2 == 0)
                {
                    printf("Case %d: %d\n", ++kag, ((tmp+1) / 2) * 4);
                    continue;
                }
                else
                {
                    printf("Case %d: %d\n", ++kag, (((tmp+1) / 2) * 4) - 2);
                    continue;
                }
            }
        }
        tmp = (row + 1) / 2;
        if( !(row % 2) ) printf("Case %d: %d\n", ++kag, tmp * col);
        else printf("Case %d: %d\n", ++kag, tmp * col - (col / 2));
    }
    return 0;
}
