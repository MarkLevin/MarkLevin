/*
 * =====================================================================================
 *
 *       Filename:  poj1002-ano.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/23/2011 09:32:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;

int alphabet[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int statistic[10000000];

int main()
{
    int n;
    cin>>n;

    memset(statistic,0,sizeof(int));
    string str[n];
    for(int i=0;i<n;i++)
    {
        cin>>str[i];

        for(int p=0;p<str[i].length();++p)
        {
            if(str[i][p]=='-'||str[i][p]=='Q'||str[i][p]=='Z')
            {
                str[i].erase(p,1);
                p--;
                continue;
            }
            if(str[i][p]<='Z'&&str[i][p]>='A')
            {
                str[i][p]=alphabet[str[i][p]-'A']+'0';
            }
        }
        ++statistic[atoi(str[i].c_str())];
        
    }

    for(int i=0;i<10000000;i++)
    {
        if(statistic[i]>1)
        {
            cout<<setfill('0')<<setw(3)<<i/10000<<"-"<<setw(4)<<i%10000<<" "<<statistic[i]<<endl;
        }
    }

}
