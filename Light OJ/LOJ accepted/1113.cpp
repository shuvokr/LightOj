#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

char in[ 102 ][ 52 ], comand[ 10 ];

int main()
{
    freopen("input.txt", "r", stdin);
    int kag = 0, T, i, pos;
    scanf("%d", &T);
    strcpy(in[ 0 ], "http://www.lightoj.com/");
    while( T-- )
    {
        printf("Case %d:\n", ++kag);
        pos = 0;
        while(~scanf("%s", comand))
        {
            //printf("      %s\n", comand);
            if(!strcmp(comand, "QUIT")) break;
            else if(!strcmp(comand, "VISIT"))
            {
                pos++;
                scanf("%s", in[ pos ]);
                //printf("     %s\n", in[ pos ]);
                puts(in[ pos ]);
                in[pos + 1][ 0 ] = NULL;
            }
            else if(!strcmp(comand, "BACK"))
            {
                pos--;
                if(pos < 0) pos = 0, puts("Ignored");
                else puts(in[ pos ]);
            }
            else
            {
                pos++;
                if(in[ pos ][ 0 ] == NULL) pos--, puts("Ignored");
                else puts(in[ pos ]);
            }
        }
        memset(in, 0, sizeof in);
        strcpy(in[ 0 ], "http://www.lightoj.com/");
    }
    return 0;
}
