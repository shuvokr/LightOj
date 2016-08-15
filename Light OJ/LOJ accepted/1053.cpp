#include<stdio.h>
int main()
{
    int t,ck=1;
    scanf("%d",&t);
    while(t>0)
    {
        long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a>b && a>c)
        {
            int m,n;
            m=(a*a);
            n=((b*b)+(c*c));
            if(m==n)
            {
                printf("Case %d: yes\n",ck);
            }
            else
            {
                printf("Case %d: no\n",ck);
            }
        }
        else if(b>a && b>c)
        {
            int m,n;
            m=(b*b);
            n=((a*a)+(c*c));
            if(m==n)
            {
                printf("Case %d: yes\n",ck);
            }
            else
            {
                printf("Case %d: no\n",ck);
            }
        }
        else
        {
            int m,n;
            m=(c*c);
            n=((a*a)+(b*b));
            if(m==n)
            {
                printf("Case %d: yes\n",ck);
            }
            else
            {
                printf("Case %d: no\n",ck);
            }
        }

        ck++;
        t--;
    }
    return 0;
}

