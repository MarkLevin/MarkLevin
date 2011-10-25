/*
 * =====================================================================================
 *
 *       Filename:  poj3468.cpp
 *
 *    Description:  A Sinple Problem with longegers
 *
 *        Version:  1.0
 *        Created:  10/22/2011 04:21:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include "stdio.h"


long long num[100000];
long long v[400000];
long long l[400000];
long long r[400000];
long long n[400000];
long long ls[400000];
long long rs[400000];
long tt=0;

void buildtree(long a,long b)
{
    ++tt;
    long x=tt;
    l[x]=a;
    r[x]=b;
    v[x]=0;
    if(b-a>1)
    {
        long mid=(a+b)>>1;
        ls[x]=tt+1; buildtree(a,mid);
        rs[x]=tt+1; buildtree(mid,b);
        n[x]=n[ls[x]]+n[rs[x]];
    }
    else n[x]=num[a];
}
void clean(long x)
{
    if(v[x]!=0)
    {
        n[x]=n[x]+(r[x]-l[x])*(long long)v[x];
        if(ls[x]!=0) v[ls[x]]=(long long)v[ls[x]]+v[x];
        if(rs[x]!=0) v[rs[x]]=(long long)v[rs[x]]+v[x];
        v[x]=0;
    }
}

long long count(long x,long a,long b)
{
    clean(x);
    if(a<=l[x]&&b>=r[x]) { return n[x];}
    long mid=(r[x]+l[x])>>1;
    long long cou=0;
    if(a<mid) cou+=count(ls[x],a,b);
    if(b>mid) cou+=count(rs[x],a,b);
    clean(ls[x]); clean(rs[x]);
    n[x]=n[ls[x]]+n[rs[x]];
    return cou;
}
void add (long x,long a,long b,long c)
{
        //if(a<=l[x]&&b>=r[x]) {n[x]+=c*(r[x]-l[x]); if(r[x]-l[x]<=1)return ;}
        clean(x);
        if(a<=l[x]&&b>=r[x]){ v[x]=v[x]+c; /* if(r[x]-l[x]<=1)*/ return ;};
        long long mid=(r[x]+l[x])>>1;
        if(a<mid) add(ls[x],a,b,c);
        if(b>mid) add(rs[x],a,b,c);
        //n[x]=n[ls[x]]+n[rs[x]];
        clean(ls[x]); clean(rs[x]);
        n[x]=n[ls[x]]+n[rs[x]];
}


int main()
{
    long leng,operat;

    scanf("%d%d\n",&leng,&operat);
    for(long i=0;i<leng;i++)
    {
        scanf("%lld",&num[i]);
    }
    buildtree(0,leng);
    

    for(long i=0;i<operat;i++)
    {
        char op[2];
        scanf("%s",&op);

        if(op[0]=='C')
        {
            long long a,b,c;
            scanf("%d%d%lld",&a,&b,&c);
            add(1,a-1,b,c);
        }
        if(op[0]=='Q')
        {
            long a,b;
            scanf("%d%d",&a,&b);
            printf("%lld\n",count(1,a-1,b));
        }

    }
}
