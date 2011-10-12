#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n==3) cout<<0;
    else
    {
        n-=3;
        int a[4][n];
        a[0][0]=1;

        for (int i=0;i<n;i++)
        {
            a[0][i]=i+1;
            a[1][i]=0;
            a[2][i]=0;
            a[3][i]=0;
        }
        a[1][0]=1;
        a[2][0]=1;
        a[3][0]=1;
        for (int i=1;i<4;i++)
        {
            for(int j=1;j<n;j++)
            {
                for(int k=0;k<=j;k++)
                    a[i][j]+=a[i-1][k];
            }
        }
        cout<<a[3][n-1]<<endl;
    }
    return 0;
}
