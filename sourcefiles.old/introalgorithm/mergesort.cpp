#include <iostream>
using namespace std;



void Merge (int *A,int r,int q,int p)
{
	int L[q-r+2];
	int R[p-q+1];
	for(int i=0;i<q-r+1;i++)
		L[i]=A[r+i];
	for(int i=0;i<p-q;i++)
		R[i]=A[q+i+1];
	L[q-r+1]=10000000;
	R[p-q]=10000000;
	int i=0;
	int j=0;
	for(int k=r;k<=p;k++)
	{
		if(L[i]>R[j]) {A[k]=R[j];j++;}
		else{A[k]=L[i];i++;}
	}
}
void MergeSort(int *A,int r,int p)
{
	int q=(r+p)/2;
	if(r<p)
	{
		MergeSort(A,r,q);
		MergeSort(A,q+1,p);
		Merge(A,r,q,p);
	}
}

int main()
{
	int a[20]={123,32,21,321,315,21312,143,231,563,132,26,32421,3765,32144,76321,4234,47636,21421,45324,321};
	MergeSort(a,0,19);
	for(int i=0;i<20;i++)
		cout<<a[i]<<endl;
}
