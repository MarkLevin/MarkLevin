/*
 * =====================================================================================
 *
 *       Filename:  poj2777.cpp
 *
 *    Description:  Count Colors
 *
 *        Version:  1.0
 *        Created:  10/21/2011 12:33:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
int ll,t,o;
int l[200000];
int r[200000];
int ls[200000];
int rs[200000];
int n[200000];
int pa[100000];
int h[30];
int tt=0;

void buildtree(int a,int b)
{
    int x;
    ++tt;
    x=tt;
    l[x]=a;
    r[x]=b;
    if(b-a>0)
    {
        int mid=(a+b)>>1;
        ls[x]=tt+1; if(b-a>1) buildtree(a,mid);
        else if(!h[a]) buildtree(a,mid);
        rs[x]=tt+1; if(b-a>1) buildtree(mid,b);
        else {buildtree(mid+1,b); h[b]=1;}
    }
}
void down(int x)
{
    if(n[x]>0)
    {
        n[ls[x]]=n[x];
        n[rs[x]]=n[x];
        n[x]=-1;
    }
}
void insert(int x,int a,int b,int c)
{
    int mid;
    if(a<=l[x]&&b>=r[x])
        n[x]=c;
    else {
        down(x);
        mid=(l[x]+r[x])>>1;
        if(a<=mid) insert(ls[x],a,b,c);
        if(b>mid) insert(rs[x],a,b,c);
    }
}

void count(int x,int a,int b)
{
    int mid;
    if(x==0) return ;
    if(n[x]>0)
    {
        h[n[x]]++;
    }
    else
    {
        mid=(l[x]+r[x])>>1;
        if(a<=mid) count(ls[x],a,b);
        if(b>mid) count(rs[x],a,b);
    }

}
int main()
{
    n[1]=1;
    cin>>ll>>t>>o;
    buildtree(0,ll-1);
    for(int i=0;i<ll;i++) pa[i]=0;
    for(int i=0;i<o;i++) 
    {
        string opera;
        cin>>opera;
        if(opera=="C")
        {
            int a,b,color;
            cin>>a>>b>>color;
            if(a>b) insert(1,b-1,a-1,color);
            else insert(1,a-1,b-1,color);
            for(int i=1;i<=tt;i++) cout<<l[i]<<" "<<r[i]<<" "<<n[i]<<" and  ";
        }
        else if(opera=="P")
        {

           for(int i=0;i<30;i++)
               h[i]=0;
           int a,b;
           cin>>a>>b;
           if (a>b) count(1,b-1,a-1);
           else count(1,a-1,b-1);
           int ans=0;
           for(int i=0;i<30;i++)
               if(h[i]>0) ans++;
           cout<<ans<<endl;
        }
    }

}
