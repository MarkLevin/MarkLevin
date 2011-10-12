#include <iostream>
using namespace std;

int main()
{
	int l,n;
	cin>>l>>n;
	string str[n];
	int revern[n];
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		revern[i]=0;

		for(int t=0;t<str[i].length();t++)
		{
			for(int j=t+1;j<str[i].length();j++)
			{
				if (str[i][t]>str[i][j]) revern[i]++;
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		int min=1000000;
		int index;
		for(int j=0;j<n;j++)
		{
			if(revern[j]<min&&revern[j]>=0)
			{
				min=revern[j];
				index=j;
			}
		}
		revern[index]=-1;
		cout<<str[index]<<endl;
	}
}
