#include <iostream>

using namespace std;

int main()
{
  int r;
  cin>>r;
  for(int i=0;i<r;i++)
  {
	long n;
	cin>>n;
	int p=n%10;
	if(p==1) cout<<1<<endl;
	else if(p==2) 
	{
		int t=n%4;
		switch(t){
		case 0: cout<<6<<endl; break;
		case 1: cout<<2<<endl; break;
		case 2: cout<<4<<endl; break;
		case 3: cout<<8<<endl; break;
		}
	}
	else if(p==3)
	{
		int t=n%4;
		switch(t){
		case 0: cout<<1<<endl; break;
		case 1: cout<<3<<endl; break;
		case 2: cout<<9<<endl; break;
		case 3: cout<<7<<endl; break;
		}
	}
	else if(p==4)
	{
		int t=n%2;
		switch(t){
		case 0: cout<<6<<endl; break;
		case 1: cout<<4<<endl; break;
		}
	}
	else if(p==5)
		cout<<5<<endl;
	else if(p==6)
		cout<<6<<endl;
	else if(p==7)
	{
		int t=n%4;
		switch(t)
		{
		case 0: cout<<1<<endl; break;
		case 1: cout<<7<<endl; break;
		case 2: cout<<9<<endl; break;
		case 3: cout<<3<<endl; break;
		}
	}
	else if(p==8)
	{
		int t=n%4;
		switch(t)
		{
		case 0: cout<<6<<endl; break;
		case 1: cout<<8<<endl; break;
		case 2: cout<<4<<endl; break;
		case 3: cout<<2<<endl; break;
		}
	}
	else if(p==9)
	{
		int t=n%2;
		switch(t)
		{
		case 0: cout<<1<<endl; break;
		case 1: cout<<9<<endl; break;
		}
	}
	else if(p==0) cout<<0<<endl;
  }
}
