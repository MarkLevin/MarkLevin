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
#include <stdio.h>
using namespace std;

int cmp(const void *a, const void *b)
{
    return (*(int *)a-*(int *)b);
}

int main()
{
    int data[250001];
    int n; 
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>data[i];

    qsort(data,n,sizeof(int), cmp);

    ///for(int i=0;i<n;i++)
     //   cout<<data[i]<<" ";
    double middle;
    int m=n/2;
    if(n%2)
        middle = data[m];
    else    
        middle=data[m-1]/2.0+data[m]/2.0;
        
    printf("%.1f\n",middle);

}
