#include <iostream>
using namespace std;

void digui()
{
	char a;
	a =cin.get();
	if(a!='\n')
		digui();
	cout<<a;
}

int main()
{
	digui();
}
