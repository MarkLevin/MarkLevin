/*
 * =====================================================================================
 *
 *       Filename:  poj2365.cpp
 *
 *    Description:  Rope
 *
 *        Version:  1.0
 *        Created:  10/20/2011 12:21:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int n,r;
    cin>>n>>r;

    double x[n],y[n];
    double leng;

    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        if(i>0)
        {
            leng+=hypot(x[i]-x[i-1],y[i]-y[i-1]);
        }
    }
    leng+=hypot(x[n-1]-x[0],y[n-1]-y[0])+3.14159*2*r;
    printf("%.2f",leng);
}

