#include <iostream>
#include <cmath>
using namespace std;
bool prime(int n)
{
	for(int i=2;i<sqrt(n);i++) if (!(n%i)) return 0;
	return 1;
}
int main()
{
	int a=2;
	for(int i=1;i<=5;)
		if (prime((a=a<<1)-1)) {cout<<a<<" "<<(a>>1)*(a-1)<<endl;i++;}
}
