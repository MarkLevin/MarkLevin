//#######################################################################
// Author: Mark.Liu
// Created Time: Tue 14 Dec 2010 07:46:04 PM CST
// File Name: 1033-pluto.cpp
// Description: 
//#######################################################################
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        int aver[t],averall=0,bypass=0;
        float bypassrate;
        for(int j=0;j<t;j++)
        {
            cin>>aver[j];
            averall+=aver[j];
        }
        averall/=t;

        for(int j=0;j<t;j++)
            if(aver[j]>averall) bypass++;

        bypassrate=(float)bypass/t;
        cout.precision(3);
        
        cout<<setprecision(3)<<setiosflags(ios::fixed)<<bypassrate*100<<"%"<<endl;
    }
     
    return 0;
}
