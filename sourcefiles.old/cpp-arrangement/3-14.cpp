#include <iostream>

using namespace std;

int main()
{
	int a[8],max=-1,min=1000000,sum=0;
	for(int i=0;i<8;i++)
	{
		cin>>a[i];
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
		sum+=a[i];
	}
	cout<<(sum-max-min)/6.0<<endl;
	return 0;
}
