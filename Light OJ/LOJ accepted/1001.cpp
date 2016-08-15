#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T>0)
    {
        int n,m;
        scanf("%d",&n);
        if(n>10)
        {
            m=n-10;
            printf("10 %d\n",m);
        }
        else
        {
            printf("%d 0\n",n);
        }

        T--;
    }
    return 0;
}

