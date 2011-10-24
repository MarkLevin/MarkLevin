/*
 * =====================================================================================
 *
 *       Filename:  poj3468.cpp
 *
 *    Description:  A Sinple Problem with Integers
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
#include <iostream>
using namespace std;

__int64 num[100000];
__int64 v[200000];
__int64 l[200000];
__int64 r[200000];
__int64 n[200000];
__int64 ls[200000];
__int64 rs[200000];
__int64 tt=0;

void buildtree(__int64 a,__int64 b)
{
    ++tt;
    __int64 x=tt;
    l[x]=a;
    r[x]=b;
    if(b-a>1)
    {
        __int64 mid=(a+b)>>1;
        ls[x]=tt+1; buildtree(a,mid);
        rs[x]=tt+1; buildtree(mid,b);
    }
}
void filltree(__int64 x)
{
    __int64 sum=0;
    for(int i=l[x];i<r[x];i++)
        sum+=num[i];
    n[x]=sum;
    if(r[x]-l[x]>1)
    {
        filltree(rs[x]);
        filltree(ls[x]);
    }
}
void clean(__int64 x)
{
    if(v[x]!=0)
        n[x]=n[x]+(r[x]-l[x])*v[x];
    if(ls[x]!=0) v[ls[x]]=v[ls[x]]+v[x];
    if(rs[x]!=0) v[rs[x]]=v[rs[x]]+v[x];
    v[x]=0;
}
__int64 result;
__int64 count(int x,int a,int b)
{
    if(a<=l[x]&&b>=r[x]) {result=n[x]; return result;}
    
    __int64 mid=(r[x]+l[x])>>1;
    __int64 cou=0;
    if(a<mid) cou+=count(ls[x],a,b);
    if(b>mid) cou+=count(rs[x],a,b);
    clean(ls[x]); clean(rs[x]);
    n[x]=n[ls[x]]+n[rs[x]];
    return cou;
}
void add (int x,int a,int b,int c)
{
        //if(a<=l[x]&&b>=r[x]) {n[x]+=c*(r[x]-l[x]); if(r[x]-l[x]<=1)return ;}
        if(a<=l[x]&&b>=r[x]){ v[x]=v[x]+c; if(r[x]-l[x]<=1) return ;};
        int mid=(r[x]+l[x])>>1;
        if(a<mid) add(ls[x],a,b,c);
        if(b>mid) add(rs[x],a,b,c);
        //n[x]=n[ls[x]]+n[rs[x]];
        clean(ls[x]); clean(rs[x]);
        n[x]=n[ls[x]]+n[rs[x]];
}

/*int count(int x,int a,int b)
{
    if(a<=l[x]&&b>=r[x])
        return n[x];
    int ans=0;
    int mid=(l[x]+r[x])>>1;
    if (a<mid)
        ans+=count(ls[x],a,b);
    if (mid>b)
        ans+=count(rs[x],a,b);
    clean(ls[x]);clean(rs[x]);
    n[x]=n[ls[x]]+n[rs[x]];
    return ans;
}*/
int main()
{
    int leng,operat;

    scanf("%d%d\n",&leng,&operat);
    for(int i=0;i<leng;i++)
    {
        scanf("%d",&num[i]);
    }
    buildtree(0,leng);
    filltree(1);
    

    for(int i=0;i<operat;i++)
    {
        char op;
        cin>>op;

        if(op=='C')
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
             //   num[i]+=c;
            add(1,a-1,b,c);
        }
        if(op=='Q')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            result=0;
            printf("%d\n",count(1,a-1,b));
        }

    }
}
