#include <iostream>

using namespace std;

void Merge( int *A, int p,int q,int r)
{
	int L[q-p+2];
	int R[r-q+1];

	for(int i=0;i<q-p+1;i++)
		L[i]=A[p+i];
	for(int i=0;i<r-q;i++)
		R[i]=A[q+i+1];

	L[q-p+1]=10000000;
	R[r-q]=10000000;

	int i=0,j=0;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<R[j]) 
			A[k]=L[i++];
		else A[k]=R[j++];
	}
}
void MergeSort (int *A, int p,int r)
{
	int q=(p+r)/2;
	if(p<r)
	{
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}

int main()
{
	int a[5]={6,4,3,2,-1};
	MergeSort(a,0,4);
	for(int i=0;i<5;i++)
		cout<<a[i]<<endl;
	return 0;
}
