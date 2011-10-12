#include <iostream>

using namespace std;

int main()
{
	int x=3;
	do
	{
		cout<<(x-=2)<<" ";
	}while(!(--x));
}
