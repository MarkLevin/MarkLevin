/*
 * =====================================================================================
 *
 *       Filename:  poj2623.cpp
 *
 *    Description: Sequence Mediance 
 *
 *        Version:  1.0
 *        Created:  10/19/2011 11:43:10 PM
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
    return (*(int *)a-*(int *)b);
}

int main()
{
    int data[250000];
    int n; 
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }

    qsort(data,n,sizeof(int), cmp);

    ///for(int i=0;i<n;i++)
     //   cout<<data[i]<<" ";
    int middle;
    if(!(n%2))
        middle=(data[n/2]+data[n/2-1])/2;
    else middle = data[n/2];
    cout<<middle;
        

}
