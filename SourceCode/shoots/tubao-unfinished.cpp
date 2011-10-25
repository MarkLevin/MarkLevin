/*
 * =====================================================================================
 *
 *       Filename:  tubao.cpp
 *
 *    Description:  just a demo in tubao
 *
 *        Version:  1.0
 *        Created:  10/24/2011 08:22:25 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double point[n][2];
    double dis[n];
    bool used[n];
    memset(used,0,sizeof(bool));
    for(int i=0;i<n;i++)
        cin>>point[i][0]>>point[i][1];
    
    int min=1000000;
    int minpoint;
    for(int i=0;i<n;i++)
    {
        dis[i]=hypot(point[i][0],point[i][1]);
        if(dis[i]<min) {min=dis[i];minpoint=i;}
    }
    used[minpoint]=false;
    int nowpoint = minpoint;
    while(1)
    {
        int neipoint;
        for(int i=0;i<n;i++) if(!used[i]) {neipoint=i;break;}
        for(int j=0;j<n&&!used[j];j++)
        {
           if(point[neipoint][0]*point[j][1]-point[j][1]*point[neipoint][1]>0)
               neipoint=j;
        }
        if(neipoint==minpoint) break;
        used[neipoint]=true;
        cout<<point[neipoint][0]<<" "<<point[neipoint][1]<<endl;
    }
}
