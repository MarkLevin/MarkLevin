#include <iostream>
using namespace std;

int insertionsort(int *A, int len)
{
	for(int j=1;j<len;j++)
	{
		int key=A[j];
		int i=j-1;
		while((i>=0)&&(A[i]>key))
		{
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=key;
	}
}


int main()
{
	int a[10]={132,41,2131,3215,321,2131,435,213,745,213};
	insertionsort(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<endl;
}
