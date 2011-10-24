/*
 * =====================================================================================
 *
 *       Filename:  poj2777.cpp
 *
 *    Description:  Count Colors
 *
 *        Version:  1.0
 *        Created:  10/22/2011 01:30:35 PM
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

int l[500000];
int r[500000];
int ls[500000];
int rs[500000];
int n[500000];
int tt=0;
int len,t,o;
int color[30];

void buildtree(int a,int b)
{
    ++tt;
    int x=tt;
    l[x]=a;
    r[x]=b;
    int mid=(a+b)>>1;
    if(b-a>1)
    {
        ls[x]=tt+1; buildtree(a,mid);
        rs[x]=tt+1; buildtree(mid,b);
    }
}
void down(int x)
{
    if (n[x]>0)
    {
        n[ls[x]]=n[x];
        n[rs[x]]=n[x];
        n[x]=-1;
    }
}
void insert(int x,int a,int b,int c)
{

    if(a<=l[x]&&b>=r[x]) n[x]=c;
    else    
    {
        down(x);
        int mid=(r[x]+l[x])>>1;
        if(a<mid)insert(ls[x],a,b,c);
        if(b>mid)insert(rs[x],a,b,c);
    }

}
void count(int x,int a,int b)
{
    if(n[x]==0) return ;
    if(n[x]>0)
        {
            color[n[x]]++;
        }
    else 
    {
        int mid=(r[x]+l[x])>>1;
        if(a<mid) count(ls[x],a,b);
        if(b>mid) count(rs[x],a,b);
    }
}

int main()
{
    cin>>len>>t>>o;
    n[1]=1;
    buildtree(0,len);
    for(int i=0;i<o;i++)
    {
        string operat;
        cin>>operat;
        if(operat=="C")
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(a<=b) insert(1,a-1,b,c);
            else insert(1,b-1,a,c);
            
        }
        else if(operat=="P")
        {
            int a,b;
            cin>>a>>b;
            for(int i=0;i<30;i++) color[i]=0;
            if(a<=b)
            count(1,a-1,b);
            else count(1,b-1,a);
            int ans=0;
            for(int i=0;i<30;i++) if(color[i]) ++ans;
            cout<<ans<<endl;
        }
    }
}
