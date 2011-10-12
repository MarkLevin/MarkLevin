#include <iostream>

using namespace std;

int main()
{
	int a,b,c,x;
	a=b=c=0;
	x=35;
	if(!a) x--;
	else if(b)
		if(c) x=3;
		else x=4;
	cout<<x<<endl;
}
