#include <iostream>
using namespace std;

void InsertionSort(int *A,int l)
{
	for(int j=1;j<l;j++)
	{
		int key=A[j];
		int i=j-1;
		while((i>=0)&&(key<A[i]))
		{
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=key;
	}
}
int main()
{
	int a[10]={211,3244,213,345,1532,3462,2131,21,1,54325};
	InsertionSort(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<endl;
}
