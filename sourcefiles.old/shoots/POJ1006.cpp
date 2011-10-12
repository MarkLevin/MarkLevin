#include <iostream>
using namespace std;
int gcd (int a,int b)
{
	while(b^=a^=b^=a%=b);
	return a;
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
int main()
{
	while(1)
	{
		int p,e,i,d;
		cin>>p>>e>>i>>d;
		if(p==-1) break;
		p=p%23;
		e=e%28;
		i=i%33;
		if(p==0) p=23;
		if(e==0) e=28;
		if(i==0) i=33;
	//	cout<<gcd(p,e)<<endl;
	//	cout<<gcd(2860,33);

		cout<<lcm(lcm(p,e),i)-d<<endl;
	}
}
