#include <iostream>

using namespace std;

int main()
{
	int x=1,y=0,a=0,b=0;
	switch(x)
	{
	case 1:
		if(y==0) a=a+1;
		else b=b+1;
		break;
	case 2:
		a=a+1;b=b+1;break;
	case 3:
		a=a+1;b=b+1;
	}
	cout<<"a="<<a<<", b="<<b<<endl;
}
