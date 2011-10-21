/*
 * =====================================================================================
 *
 *       Filename:  poj1298.cpp
 *
 *    Description:  The Hardest Problem Ever
 *
 *        Version:  1.0
 *        Created:  10/20/2011 12:34:33 AM
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
    string start;
    getline(cin,start);
    while(start!="ENDOFINPUT")
    {
        string content;
        getline(cin,content);
        for(int i=0;i<content.length();i++)
        {
            if(content[i]<='Z'&&content[i]>='A')
            {
                content[i]=content[i]-5;
                if(content[i]<'A')
                    content[i]+=26;
            }
        }
        cout<<content<<endl;
        string end;
        getline(cin,end);
        getline(cin,start);
    }
}
