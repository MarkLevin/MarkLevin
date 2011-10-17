/*
 * =====================================================================================
 *
 *       Filename:  poj1008.cpp
 *
 *    Description:  Maya Calendar
 *
 *        Version:  1.0
 *        Created:  10/17/2011 02:46:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

string haab[19]=
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
string tozlkin[20]=
{"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};


int main()
{
    int n;
    cin>>n;
    cout<<n<<endl;
    
    for(int i=0;i<n;i++)
    {
        int date;
        int y,m,d;
        string ds,ms;
        cin>>ds>>ms>>y;
        ds.erase(ds.length()-1);
        d=atof(ds.c_str());
        for(int i=0;i<19;i++)
        {
            if(ms==haab[i]) m=i;   
        }

        date=y*365+m*20+d;

        int ty,ts,tn;
        ty=date/360;
        date=date%360;

        tn=date%13+1;
        ts=date%20;

        cout<<tn<<" "<<tozlkin[ts]<<ty<<endl;

    }
}
