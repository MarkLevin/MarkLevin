/*
 * =====================================================================================
 *
 *       Filename:  poj1163.cpp
 *
 *    Description:  The Triangle
 *
 *        Version:  1.0
 *        Created:  10/23/2011 03:52:41 PM
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

int main()
{
    int n;
    cin>>n;
    int f[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(j<=i)cin>>f[i][j];
            else f[i][j]=0;
        }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(f[i][j]>f[i][j+1]) f[i-1][j]+=f[i][j];
            else f[i-1][j]+=f[i][j+1];
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
        {
            cout<<f[i][j];
        }
    int max=-1;
    cout<<endl;
    cout<<f[0][0]<<endl;
}



