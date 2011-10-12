#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	ofstream out ("POJ1005f.cpp",ios::out);
	for(int i=1;i<500;i++)
	{
		out<<"a["<<i<<"]="<<sqrt(i*50*2/3.14)<<";"<<endl;
	}
}
