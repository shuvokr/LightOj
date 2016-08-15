#include <stdio.h>
#include <string.h>

struct matrix
{
    long long ar[ 3 ][ 3 ];
};

matrix matrix_expo(matrix a, long long p);
matrix multiply(matrix a, matrix b);

long long aa, bb, n, m, mod;
matrix array;

int main()
{
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%lld %lld %lld %lld", &aa, &bb, &n, &m);

        mod = 1; for(int i = 0; i < m; i++) mod *= 10;

        //Important
        //Initial matrix ar 1st row ar sob position a 1 rakte hobe
        //example::
        //1 1 1 1
        //1 0 0 0
        //0 1 0 0
        //0 0 1 0

        array.ar[ 0 ][ 0 ] =  array.ar[ 0 ][ 1 ] = array.ar[ 1 ][ 0 ] = 1;
        array.ar[ 1 ][ 1 ] = 0;

        array = matrix_expo(array, n - 1); // n - 1 cause prothom pod 0 theke suru, Jodi 1 thake suru hoto then n - 2

        printf("Case %d: %lld\n", ++kag, (((array.ar[ 0 ][ 0 ] * bb) % mod) + ((array.ar[ 0 ][ 1 ] * aa) % mod)) % mod);
    }
    return 0;
}
matrix matrix_expo(matrix a, long long p)
{
    if(p == 1) return a;
    if(p % 2) return multiply(a, matrix_expo(a, p - 1));
    matrix ret = matrix_expo(a, p / 2);
    return multiply(ret, ret);
}
matrix multiply(matrix a, matrix b)
{
    matrix ret;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            long long sum = 0ll;
            for(int k = 0; k < 2; k++) sum += a.ar[ i ][ k ] * b.ar[ k ][ j ];
            ret.ar[ i ][ j ] = sum % mod;
        }
    }
    return ret;
}
