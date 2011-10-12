#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int MAXSIZE=100000;
	int n;
	cin>>n;
	int result[n];
	for(int p=0;p<n;p++)
	{
		int x,B,X,Y;
		int a[MAXSIZE],b[MAXSIZE];
		for(int i=0;i<MAXSIZE;i++) {a[i]=0;b[i]=0;}
		int j=0,t=0;
		cin>>x>>B>>X>>Y;
		while(X!=0)
		{
			a[j]=X%B;
			X=X/B;
			j++;
		}
		while(Y!=0)
		{
			b[t]=Y%B;
			Y=Y/B;
			t++;
		}
		int lengt=(j>t)?j:t+1;
		for(int i=0;i<lengt;i++)
		{
			a[i]+=b[i];
			a[i]%=B;
		}
		int sum=0;
		for(int i=0;i<lengt;i++)
		{
			sum+=pow(B,i)*a[i];
		}
		result[p]=sum;
	}
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" "<<result[i]<<endl;
	}
	return 0;
}
