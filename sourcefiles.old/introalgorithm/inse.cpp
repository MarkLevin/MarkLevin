#include <iostream>
using namespace std;

void insertionsort(int *a,int n)
{
	for(int i=1;i<n;i++)
	{
		int key=a[i];
		int j=i-1;
		while(a[j]>key&&j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

int main()
{
	int a[10]={1431,24361,1646,264,72,16,3215,15,314,16};
	insertionsort(a,10);

	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	return 0;

}
