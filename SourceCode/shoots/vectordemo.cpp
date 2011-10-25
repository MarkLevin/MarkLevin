/*
 * =====================================================================================
 *
 *       Filename:  vectordemo.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/24/2011 09:09:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        v.push_back(i);

    for(vector<int>::iterator it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<accumulate(v.begin(),v.end(),0)<<endl;
    return 0;

}
