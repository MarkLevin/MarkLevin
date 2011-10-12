#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	while(1)
	{
		int a=0;
		if(scanf("%d",&a))
		{
			cout<<"a="<<a<<endl;
			cout<<scanf("%d",&a);
			break;
		}
	}
}
