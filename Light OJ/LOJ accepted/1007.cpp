#include <stdio.h>
template <class T> T sq(T x) {return x * x;}


long long pr = 5000001, phi[ 5000001 ];
void primelist()
{
    for(int i = 0; i < pr; i++) phi[ i ] = i; phi[ 1 ] = 0;
    for(int i = 2; i < pr; i++)
        if(phi[ i ] == i)
            for(int j = i; j < pr; j += i) phi[ j ] -= phi[ j ] / i;
    for(int i = 2; i < pr; i++) phi[ i ] = phi[i - 1] + sq( phi[ i ] );
}

void input();

int main()
{
    primelist();
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    int a, b, T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", ++kag, phi[ b ] - phi[a - 1]);
    }
}

