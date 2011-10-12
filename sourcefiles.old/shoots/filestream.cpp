#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("filestream.in",ios::in);
	ofstream out("filestream.out",ios::out);

	int a;
	in>>a;
	out<<a;
	in.close();
	out.close();
	return 0;
}
