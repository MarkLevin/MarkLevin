#include <stdio.h> 
int a[100010];
int main()
{
	int j;

	for (j=0;j<=100000;j++)
	{
		if (j>2) a[j]=(a[j-1]+a[j-2])%10007;
		else a[j]=j+1;
	} 
	int q=0;
	while(scanf ("%d",&q)!=EOF)
	{
		printf("%d\n",a[q]);
	}

	return 0;
}
