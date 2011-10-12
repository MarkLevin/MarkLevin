#include <iostream>
using namespace std;

int insertionsort(int *A , int a)
{
	if(a==0) return 0;
	else
	{
		insertionsort(A,a-1);
		int key=A[a];
		int i=a-1;
		while ((i>=0)&&(A[i]>key))
            {A[(i--)+1]=A[i];}
        A[i+1]=key;
	}
}

int main()
{
	int a[10]={214,21,32,213,2133,324,563,45,1342,321};
	insertionsort(a,9);
	for(int i=0;i<10;i++)
		cout<<a[i]<<endl;
}
