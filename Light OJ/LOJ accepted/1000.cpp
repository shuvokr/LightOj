#include<stdio.h>
int main()
{
    int t,a,b,r,c=1;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d%d",&a,&b);

        printf("Case %d: %d\n",c,r=(a+b));

        c++;
        t--;
    }
    return 0;
}
