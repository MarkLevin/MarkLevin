//#######################################################################
// Author: Mark.Liu
// Created Time: Tue 14 Dec 2010 07:28:47 PM CST
// File Name: 1073-countsheep.cpp
// Description: So Easy...
//#######################################################################
#include <iostream>
using namespace std;

int main(){
    int n;
    
    cin>>n;

    int s=0,t=0;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a==0) s++;
        else if(a==1) t++;
    }
    cout<<s-t<<endl;
     
    return 0;
}
