//#######################################################################
// Author: Mark.Liu
// Created Time: Tue 14 Dec 2010 08:23:51 PM CST
// File Name: 1028-banana.cpp
// Description: 
//#######################################################################
#include <iostream>
using namespace std;

void QSort(int *pData, int left, int right)
{
    int i,j;
    int middle,iTemp;
    i=left;
    j=right;

    middle=pData[(left+right)/2];
    do
    {
        while ((pData[i] < middle)&&(i<right))
            i++;
        while ((pData[j] > middle)&&(j>left))
            j--;
        if(i<=j)
        {
            iTemp=pData[i];
            pData[i]=pData[j];
            pData[j]=iTemp;
            i++;
            j--;
        }
    }while(i<=j);

    if(left<j)
        QSort(pData,left,j);
    if(right>i)
        QSort(pData,i,right);
}

int main(){
    int m,n;
    cin>>m>>n;
    int a[m],b[n];
    for(int i=0;i<m;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

    QSort(a,0,m-1);
    QSort(b,0,n-1);
    int t=n-1,r=0;

    for(int i=m-1;i>=0;i--)
    {
        while(t>=0)
        {
            if(a[i]>b[t]) 
            {
                t--;
                r++;
                break;
            }
            else t--;
        }
    }
    cout<<m+r<<endl;

    return 0;
}
