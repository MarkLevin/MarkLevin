#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double sum=0;
	for(int i=0;i<12;i++)
	{
		double t;
		cin>>t;
		sum+=t;
	}
	cout<<"$"<<setprecision(2)<<setiosflags(ios::fixed)<<sum/12.0<<endl;
}
