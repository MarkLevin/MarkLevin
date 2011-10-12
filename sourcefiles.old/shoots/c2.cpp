#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main()
{
	int l,q;
	double result;
	while((scanf("%d%d",&l,&q))!=EOF)
	{ 
		int temp2=0;
		int a[100000+10]={0};
		int sum=0;
		while(q--)
		{
			int temp;
			scanf("%d",&temp);
			if(temp){
				int p,v;
				cin>>p>>v;
				a[p]+=v;
			}
			else {
				int x,y;
				cin>>x>>y;
				for(int i=x;i<=y;i++)
				{
					sum+=i*a[i];
					temp2+=a[i];
				}
				result=sum/(temp2);
				cout<<setiosflags(ios::fixed);
				cout<<setprecision(2)<<result<<endl;
			}
		} 
	}
	return 0;
}

