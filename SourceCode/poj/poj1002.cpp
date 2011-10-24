/*
 * =====================================================================================
 *
 *       Filename:  poj1002.cpp
 *
 *    Description:  487-3279
 *
 *        Version:  1.0
 *        Created:  10/23/2011 11:16:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
int num[10000000];

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
   int n;
   cin>>n;
   memset(num,0,sizeof(num));
   while(n--)
    {
        string str;
        cin>>str;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='-'||str[i]=='Q'||str[i]=='Z') {str.erase(i,1); --i; continue;}
            if(str[i]=='A'||str[i]=='B'||str[i]=='C') str[i]='2';
            else if(str[i]=='D'||str[i]=='E'||str[i]=='F') str[i]='3';
            else if(str[i]=='G'||str[i]=='H'||str[i]=='I') str[i]='4';
            else if(str[i]=='J'||str[i]=='K'||str[i]=='L') str[i]='5';
            else if(str[i]=='M'||str[i]=='N'||str[i]=='O') str[i]='6';
            else if(str[i]=='P'||str[i]=='R'||str[i]=='S') str[i]='7';
            else if(str[i]=='T'||str[i]=='U'||str[i]=='V') str[i]='8';
            else if(str[i]=='W'||str[i]=='X'||str[i]=='Y') str[i]='9';
        }
        num[atoi(str.c_str())]++;
    }
   int tt=true;
   for(int i=0;i<10000000;i++) 
   {
       if(num[i]>1) {tt=false;cout<<setfill('0')<<setw(3)<<i/10000<<"-"<<setw(4)<<i%10000<<" "<<num[i]<<endl;}
   }
   if(tt) cout<<"No Duplicates"<<endl;
}
