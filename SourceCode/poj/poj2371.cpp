/*
 * =====================================================================================
 *
 *       Filename:  poj2371.cpp
 *
 *    Description:  Questions and answers
 *
 *        Version:  1.0
 *        Created:  10/19/2011 11:55:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

int cmp(const void *a, const void *b)
{
    return (*(int *)a-*(int *)b );
}

int main()
{
    int n;
    cin>>n;
    int data[n];

    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }

    qsort(data,n,sizeof(int),cmp);

    string a;cin>>a;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        cout<<data[t-1]<<endl;
    }

}
