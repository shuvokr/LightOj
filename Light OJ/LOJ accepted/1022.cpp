#include<stdio.h>
#include<math.h>
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t>0)
    {
        long double r,result;
        scanf("%Lf",&r);
        result=(pow((r+r),2))-(3.1415926535897932384626433832795*(pow(r,2)));
        printf("Case %d: %.2Lf\n",c,result);
        c++;
        t--;
    }
    return 0;
}
