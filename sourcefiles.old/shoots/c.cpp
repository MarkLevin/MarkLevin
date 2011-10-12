#include <stdio.h>
using namespace std;
int main()
{
	int l,q;
	double result;
	while(scanf("%d",&l)!=EOF)
	{ 
		scanf("%d",&q);
		int temp2=0;
		int a[100000+10]={0};
		int sum=0;
		while(q--)
		{
			int temp;
			scanf("%d",&temp);
			if(temp){
				int p,v;
				scanf("%d%d",&p,&v);
				a[p]+=v;
			}
			else {
				int x,y;
				scanf("%d%d",&x,&y);
				for(int i=x;i<=y;i++)
				{
					sum+=i*a[i];
					temp2+=a[i];
				}
				result=sum/(temp2);
				printf("%.2f\n",result);
			}
		} 
	}
	return 0;
}
