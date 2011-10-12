//Mon Mar 14 20:23:30 CST 2011
#include <iostream>
using namespace std;
void qSort(string *pData,int left,int right)
{
	int i,j;
	string middle,iTemp;
	i=left;
	j=right;

	middle=pData[(left+right)/2];
	do
	{
		while((pData[i]<middle)&&(i<right)) i++;
		while((pData[j]>middle)&&(j>left )) j--;
		if(i<=j)
		{
			iTemp=pData[i];
			pData[i]=pData[j];
			pData[j]=iTemp;
			i++;
			j--;
		}
	}while(i<=j);
	if(left<j) qSort(pData,left,j);
	if(right>i) qSort(pData,i,right);
}

int main()
{
	int n;
	cin>>n;

	string str[n];
	for(int i=0;i<n;i++) cin>>str[i];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<str[i].length();j++)
			{
				if(str[i][j]=='-') {str[i].erase(j,1);j--;}
				else if(str[i][j]=='A'||str[i][j]=='B'||str[i][j]=='C') str[i][j]='2';
				else if(str[i][j]=='D'||str[i][j]=='E'||str[i][j]=='F') str[i][j]='3';
				else if(str[i][j]=='G'||str[i][j]=='H'||str[i][j]=='I') str[i][j]='4';
				else if(str[i][j]=='J'||str[i][j]=='K'||str[i][j]=='L') str[i][j]='5';
				else if(str[i][j]=='M'||str[i][j]=='N'||str[i][j]=='O') str[i][j]='6';
				else if(str[i][j]=='P'||str[i][j]=='R'||str[i][j]=='S') str[i][j]='7';
				else if(str[i][j]=='T'||str[i][j]=='U'||str[i][j]=='V') str[i][j]='8';
				else if(str[i][j]=='W'||str[i][j]=='X'||str[i][j]=='Y') str[i][j]='9';
			}
	}
	qSort(str,0,n-1);

	int flag[n];
	for(int i=0;i<n;i++) flag[i]=0;
	for(int i=0;i<n;)
	{
		int j=i+1;
		for(;j<n;j++)
		{
			if(str[i]==str[j]) flag[i]++;
			else break;
		}
		i=j;
	}
	int dupl=0;
	for(int i=0;i<n;i++) if(flag[i]) dupl=1;
	if(dupl)
		for(int i=0;i<n;i++)
		{
			if(flag[i])
			{
				for(int j=0;j<8;j++)
				{
					cout<<str[i][j];
					if(j==2) cout<<'-';
				}
				cout<<' '<<flag[i]+1<<endl;
			}
		}
		else cout<<"No duplicates."<<endl;

	return 0;
}
