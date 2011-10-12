//#######################################################################
// Author: Mark.Liu
// Created Time: Tue 14 Dec 2010 07:35:13 PM CST
// File Name: 1031-chocolate.cpp
// Description: 
//#######################################################################
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool flag=true;
    
    for(int i=0;i<20000;i++)
        if(i*i==n)
         {
            cout<<"Yes"<<endl;
            flag=false;
         }
    if(flag) cout<<"No"<<endl;
     
    return 0;
}
