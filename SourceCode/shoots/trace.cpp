#define D(a) cout << #a "=[" << a << "]" <<endl;
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	void* a=D(a);
	D(a);
	int b=3;
	string fuck="abc""def";
	D(fuck);
	if(b==3) return EXIT_FAILURE;
	cout<<__FILE__<<endl;
	cout<<__LINE__<<endl;
	return EXIT_SUCCESS;
}
