#include <stdio.h>
int main()
{
int kag = 0, T;
long long res, n, m;
scanf("%d", &T);
while( T-- )
{
      scanf("%lld %lld", &n, &m);
      printf("Case %d: %lld\n", ++kag, n * m / 2);
}
return 0;
}
