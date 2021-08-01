#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
bool isSSqDPSq(long int n,int adOn)
{
    long int s=0,sq,r;
    while(n>0)
    {
		r=n%10;
		if(r==0)
		return false;
        s=s+(r*r);
        n=n/10;
    }
	s=s+adOn;
	sq=pow(s,0.5);
	if(sq*sq==s)
    	return true;
    else
    	return false;
}
long int sumSq(long int* n,int i)
{
    long int s=0,r;
    for(r=0;r<i;r++)
    {
        s=s+(n[r]*n[r]);
    }
    return s;
}
void aboveF(long int n)
{
    long int rn,rnplusonesq,diff;
    rn=pow(n,0.5);
    if(rn*rn!=n)
    rn=rn+1;
    rnplusonesq=rn*rn;
    diff = rnplusonesq-n;
    if(diff>=404)
    {
        long int differ,seq,ckn,i,j,*temp,stin,enin,f,k,flag,iter;
        if(diff%81==0)
        differ=(diff/81);
        else
        differ=(diff/81)+1;
        for(;differ<=(diff/81)+6;differ++)
        {
            seq=differ-6;
            ckn=6;
            stin=0;
			temp=(long int*)calloc(seq,sizeof(long int));
            for(j=0;j<seq;j++)
            temp[j]=9;
            for(i=0;i<ckn;i++)
            {
                stin=stin+(pow(10,i));
            }
            enin=pow(10,i)-1;
            for(i=seq;i>=0;i--)
            {
                f=0;
                for(j=stin;j<=enin;j++)
                {
                    if(isSSqDPSq(j,n-differ+sumSq(temp,seq)))
                    {
                        f=1;
                        for(k=1;k<=(n-differ);k++)
                           printf("1");
                        printf("%ld",j);
						for(k=0;k<seq;k++)
						{
						    printf("%d",temp[k]);
						}
						printf("\n");
                        break;
                    }
                }
                if(f)
                break;
            }
            if(f)
            break;
        }
    }
    else if(diff==1||diff==2||diff==4||diff==5||diff==7||diff==10||diff==13)
    {
            rnplusonesq=(rn+1)*(rn+1);
            diff = rnplusonesq-n;
            long int differ,seq,ckn,i,j,*temp,stin,enin,f,k,flag,iter;
            if(diff>404)
            {
                for(differ=(diff%81==0)?(diff/81):(diff/81)+1;differ<=(diff/81)+6;differ++)
                {
                    seq=differ-5;
                    ckn=5;
                    stin=0;
                    temp=(long int*)calloc(seq,sizeof(long int));
                    for(j=0;j<seq;j++)
                    temp[j]=9;
                    for(i=0;i<ckn;i++)
                    {
                        stin=stin+(pow(10,i));
                    }
                    enin=pow(10,i)-1;
                    for(i=seq;i>=0;i--)
                    {
                        f=0;
                        for(j=stin;j<=enin;j++)
                        {
                            if(isSSqDPSq(j,(n-differ+sumSq(temp,seq))))
                            {
                                f=1;
                                for(k=1;k<=n-differ;k++)
                                    printf("1");
                                printf("%ld",j);
                                for(k=0;k<seq;k++)
                                {
                                    printf("%d",temp[k]);
                                }
                                printf("\n");
                                break;
                            }
                        }
                        if(f)
                        break;
                    }
                    if(f)
                    break;
                }
            }
            else
            {
                long int f1,fl,k1,ao,m,l;
                long int j;
                fl=0;
                for(ao=n-1;ao>=0;ao--)
                {
                    f1=0,j=0;
                    l=n-ao;
                    for(k1=0;k1<l;k1++)
                    j=j*10+1;
                    m=(pow(10,l))-1;
                    for(;j<=m;j++)
                    {
                        if(isSSqDPSq(j,ao))
                        {
                            f1=1;
                            for(k1=1;k1<=ao;k1++)
                                printf("1");
                            printf("%ld\n",j);
                            fl=1;
                            break;
                        }
                    }
                    if(f1)
                    {
                        break;
                    }
                }
            }
    }
    else
    {
        long int f1,k1,ao,m,l;
        long int j;
        for(ao=n-1;ao>=0;ao--)
        {
            f1=0,j=0;
            l=n-ao;
            for(k1=0;k1<l;k1++)
                    j=j*10+1;
            m=(pow(10,l))-1;
            for(;j<=m;j++)
            {
                if(isSSqDPSq(j,ao))
                {
                    f1=1;
                    for(k1=1;k1<=ao;k1++)
                        printf("1");
                    printf("%ld\n",j);
                    break;
                }
            }
            if(f1)
            {
                break;
            }
        }
    }
}
int main()
{
    int t,*a,i,j;
    scanf("%d",&t);
    a = (int *)calloc(t,sizeof(int));
    for(i=0;i<t;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<t;i++)
    {
		aboveF(a[i]);
    }
    return 0;
}
