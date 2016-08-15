#include<stdio.h>
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t>0)
    {
        int i,n,r,Result=0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&r);
            if(r>=0)
            {
                Result+=r;
            }
        }
        printf("Case %d: %d\n",c,Result);

        c++;
        t--;
    }
    return 0;
}
