#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define CLR(n, v) memset(n, v, sizeof n)

int main()
{
    int mark[ 8010 ];
    int n, m, kag = 0, T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &n, &m);
        CLR(mark, 0);
        for(int i = 0; i < n; i++)
        {
            int u, v, us, vs;
            char a[ 8 ], b[ 8 ];
            scanf("%s %s", a, b);
            if(a[ 0 ] == '+') us = 1;
            else us = 0;
            if(b[ 0 ] == '+') vs = 1;
            else vs = 0;
            char tmp[ 8 ]; int len = strlen(a);
            int l;
            for(l = 1; l < len; l++) tmp[l - 1] = a[ l ];
            tmp[l - 1] = NULL; u = atoi( tmp );
            len = strlen(b);
            for(l = 1; l < len; l++) tmp[l - 1] = a[ l ];
            tmp[l - 1] = NULL; v = atoi( tmp );

            if(us) mark[ u ]++;
            if(vs) mark[ v ]++;
            if(!us) mark[ u ]--;
            if(!vs) mark[ v ]--;
        }
        int x[ 8010 ], cou = 0;
        for(int l = 1; l <= m; l++) if(mark[ l ] > -1) x[ cou++ ] = l;
        printf("Case %d: Yes\n", ++kag);
        printf("%d", cou);
        for(int j = 0; j < cou; j++) printf(" %d", x[ j ]);
        puts("");
    }
    return 0;
}
