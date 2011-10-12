#include <iostream>

using namespace std;

int main()
{
	int *p;

	int b=3;
	p=&b;

	for(int i;;i++)
	{
		cout<<*(p+i)<<" "<<i<<endl;
	}
	cout<<endl;
}
