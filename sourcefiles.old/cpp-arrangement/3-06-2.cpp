#include <iostream>

using namespace std;

int main()
{
	int i=1;
	while(i<=15)
		if(++i%3!=2)
			continue;
		else
			cout<<"i="<<i<<endl;
}
