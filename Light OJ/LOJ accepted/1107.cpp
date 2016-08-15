    #include<stdio.h>
    int main()
    {
        int t,ck=1;
        scanf("%d",&t);
        while(t>0)
        {
            int x1,y1,x2,y2,cow,x,y,i,j;
            scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&cow);
            printf("Case %d:\n",ck);
            while(cow>0)
            {
                scanf("%d %d",&x,&y);
                if((x>=x1 && y>=y1 && x<=x2 && y<=y2))
                {
                    printf("Yes\n");
                }
                else
                {
                    printf("No\n");
                }
                cow--;
            }
            ck++;
            t--;
        }
        return 0;
    }

