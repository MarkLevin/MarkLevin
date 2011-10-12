#include <iostream>
using namespace std;

int n;
int zhuangtai[10];
int sequence[10];

void init()
{
	cin>>n;
	for(int i=0;i<10;i++) zhuangtai[i]=1;
}
int count=0;
void dfs(int depth)
{
	if(depth==0)
	{
		for(int i=0;i<n;i++) cout<<sequence[i];
		cout<<" ";
		++count;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(zhuangtai[i])
			{
				zhuangtai[i]=0;
				sequence[n-depth]=i;
				dfs(depth-1);
				zhuangtai[i]=1;
			}

		}
	}
}

int main()
{
	init();
	dfs(n);
	cout<<count<<endl;
}
