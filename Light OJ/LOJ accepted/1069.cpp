#include<stdio.h>
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t>0)
    {
        int me,lift,result,s;
        scanf("%d%d",&me,&lift);
        if(me<=lift)
        {
            result=(lift*4)+19;
        }
        else
        {
            s=(me-lift)*4;
            result=(me*4)+19+s;
        }
        printf("Case %d: %d\n",c,result);

        c++;
        t--;
    }
    return 0;
}

