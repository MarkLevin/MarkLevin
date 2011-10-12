#include <iostream>
using namespace std;
int main()
{
	int a[10]={12321,2131,213,3245,14,2134,62,24,27,213};

	for(int i=0;i<10;i++)
	{
		int lest=100000000;
		int index;
		for(int j=i;j<10;j++)
		{
			if(a[j]<lest)
			{
				lest=a[j];
				index=j;
			}
		}
		int temp;
		temp=a[i];
		a[i]=a[index];
		a[index]=temp;
		cout<<a[i]<<endl;
	}
}
