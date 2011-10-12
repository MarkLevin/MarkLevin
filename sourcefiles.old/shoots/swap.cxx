#include <iostream>
#include <cstring>
using namespace std;

void swap(char **ap,char **bp)
{
	char **t;
	t=ap;
	ap=bp;
	bp=t;
	
}
int main()
{
	char *ap = "hello";
	char *bp = "how are you";
	swap (ap,bp);

	cout<<ap<<endl<<bp;
}
