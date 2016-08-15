#include<stdio.h>
#include<math.h>
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t>0)
    {
        long int n,len,i,s,k,r=0,rr;
        scanf("%ld",&n);
        if(n==0)
        {
            printf("Case %d: Yes\n",c);
        }
        else
        {
            rr=n;
            len=log10(n)+1;
            for(i=len-1; i>=0; i--)
            {
                s=n%10;
                r+=(s*pow(10,i));
                n=n/10;
            }
            if(rr==r)
            {
                printf("Case %d: Yes\n",c);
            }
            else
            {
                printf("Case %d: No\n",c);
            }
        }
        c++;
        t--;
    }
    return 0;
}
