#include "stdio.h" 
#include <iostream>
#include <fstream>
using namespace std;
int a[100010];
int s;
int p[10000];
int main()
{

	ofstream out("table",ios::out);
	for (int j=0;j<=100000;j++)
	{
		if (j>2) a[j]=(a[j-1]+a[j-2])%10007;
		else a[j]=j+1;
	} 
	for(int i=0;i<=100000;i++)
		out<<"a["<<i<<"]="<<a[i]<<";"<<endl;
	out.close();

	return 0;
}
