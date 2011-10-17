/*
 * =====================================================================================
 *
 *       Filename:  arrangements.cpp
 *
 *    Description:  a Recursion implement of Full arrangement
 *
 *        Version:  1.0
 *        Created:  10/17/2011 09:10:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mark Levin 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;


int n=0;
long long usage=0;


void arran(int depth)
{
    if(depth==0) 
    {
        cout<<" ";
        return ;
    }
    else for(int i=1;i<=n;i++)
    {
        if(!(i&usage))
        {
            int t=usage;
            usage=usage|(1<<(i-1));
            arran(depth-1);
            usage=t;
            cout<<i;
        }
    }
}

int main()
{
    cin>>n;
    arran(n);
}
