#include <iostream>
using namespace std;

void insertion(int *a, int len)
{
	for(int j=1;j<len;j++)
	{
		int key=a[j];
		int i=j-1;
		while(i>=0&&a[i]>key)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}

int main()
{
	int a[10]={1231,3215,1243,236,134,145,1325,16,153,135};
	insertion(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	return 0;

}
