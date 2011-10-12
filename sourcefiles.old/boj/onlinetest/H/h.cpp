#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		int sum=0;
		for(int i=0;i<str.length();i++)
		{
			sum+=str[i]-'0';
		}
		cout<<sum<<endl;
		while(sum>=10)
		{
			int p=0;
			while(sum>10)
			{
				p+=sum%10;
				sum=sum/10;
			}
			sum=p;
			
		}
		cout<<sum;
	}
}
