#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
int main()
{
    int t,i,j,k,l,tcases,*answer,ansindex;
    scanf("%d",&t);
    answer = (int*)malloc(t*sizeof(int));
    for(i=0;i<t;i++)
    {
        scanf("%d",&tcases);
        if(tcases==1)
        {
            int c=0;
            char prev[10];
            scanf("%s",&prev);
            for(k=0;k<10;k++)
            {
                if(prev[k]=='1')
                c++;
            }
            printf("%d\n",c);
            continue;
        }
        char prev[11];
        char next[11];
        for(j=0;j<tcases-1;j++)
        {
            if(j==0)
            {
                scanf("%s",&prev);
            }
            scanf("%s",&next);
            for(k=0;k<10;k++)
            {
                if(next[k]=='1'&&prev[k]=='1')
                {
                    prev[k]='0';
                    next[k]='0';
                }
                else if(prev[k]=='0'&&next[k]=='1')
                {
                    prev[k]='1';
                }
            }
        }
        int c=0;
        for(k=0;k<10;k++)
        {
            if(prev[k]=='1')
            c++;
        }
        printf("%d\n",c);
    }
    return 0;
}
