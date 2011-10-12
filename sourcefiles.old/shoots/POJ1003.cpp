#include <iostream>
using namespace std;


int main()
{
  while(1)
  {
    double t,sum=0;
    cin>>t;
    if (t<0.0001&&t>-0.0001) break;

    int i;

    for (i=2;;i++)
    {
      sum+=1.0/i;
      if (sum>t) {cout<<i-1<<" card(s)"<<endl;break;}
    }
  }
  
}
