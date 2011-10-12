#include<iostream>
#include<cmath>
using namespace std;
int main()
{


    char i,j,k;
    for(i='x';i<='z';i++)
        for(int j='x';j<='z';j++)
            for(int k='x';k<='z';k++)
                if(i!=j&&j!=k&&k!=i)
                    if(i!='x'&&k!='x'&&k!='z')
                        cout<<i<<' '<<(char)j<<' '<<(char)k<<endl;
                        cout<<"a"<<' '<<"b"<<' '<<"c"<<endl;
}
