#include <iostream>

using namespace std;

int main()
{
	int vmax,n;
	cin>>vmax>>n;
	int v[n],c[n];
	for(int i=0;i<n;i++)
		cin>>v[i]>>c[i];
	int mv[n][vmax];
	for(int i=0;i<vmax;++i) mv[0][i]=0;
	for(int i=0;i<n;   ++i) mv[i][0]=0;

	for(int i=1;i<n;++i)
	{
		for(int j=1;j<vmax;++j)
		{
			if(j>=v[n])
			{
				if(mv[i-1][j]<mv[i-1][j-v[i]]+c[i])
					mv[i][j]=mv[i-1][j-v[i]]+c[i];
				else
					mv[i][j]=mv[i-1][j];
			}
			else mv[i][j]=mv[i-1][j];
		}
	}
	cout<<mv[n-1][vmax-1];
}
