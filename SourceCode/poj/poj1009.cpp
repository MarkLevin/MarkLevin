/*
 * =====================================================================================
 *
 *       Filename:  poj1009.cpp
 *
 *    Description:  Edge Detection
 *
 *        Version:  1.0
 *        Created:  10/18/2011 07:36:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n)
        {
            int pixel[1000],runlength[1000];
            int i=0,sumlength=0;
            while(1)
            {
                cin>>pixel[i]>>runlength[i];
                if(pixel[i]||runlength[i])
                {
                    sumlength+=runlength[i];
                }
                else break;
            }
            
            for(int i=0;i<sumlength;i++)
            {
                int upper=i-n;
                int left =i-1;
                int lower=i+n;
                int right=i+1;
            }

        }
        else break;
    }
}
