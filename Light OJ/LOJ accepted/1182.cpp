#include<stdio.h>
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t>0)
    {
        long long int n,memory,k=0;
        scanf("%lld",&n);
        while(n>0)
        {
            memory=n%2;
            if(memory==1)
            {
                k++;
            }
            n=n/2;
        }
        if(k%2==0)
        {
            printf("Case %d: even\n",c);
        }
        else
        {
            printf("Case %d: odd\n",c);
        }

        c++;
        t--;
    }
    return 0;
}


