#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ofstream out("flopout.out",ios::out);
	int a[2619450];
	for(int i=0;i<261900;i++)
	{
		a[i]=i;
		out<<i<<" ";
	}
	return 0;
}
