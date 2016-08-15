#include <stdio.h>
using namespace std;
int main()
{
    int T, kag = 0;
    double P, N, M, K;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%lf %lf %lf %lf", &N, &M, &K, &P);
        printf("Case %d: %lf\n", ++kag, N * K * P);
    }
    return 0;
}

