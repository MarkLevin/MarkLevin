#include "stdio.h"
int main(){
	int k,d;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int zongshu=0;
		scanf("%d",&k);
		scanf("%d",&d);
		for(int i=1;i<=n;i++){
			int cou=0;
			int weishu = 0;
			int z = 1;
			int a = i;
			do
			{
				++weishu;
				z *= 10;
			}while(z<=a);
			int sha=i;
			while(weishu-->=1){
				int j=sha%10;
				if(j==d) cou++;
				sha=sha/10;
			}
			if(cou==k) zongshu++;
		}
		printf("%d\n",zongshu);
	}
	return 0;
}
