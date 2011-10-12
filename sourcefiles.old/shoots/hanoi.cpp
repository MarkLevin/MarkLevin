#include <iostream>
#include <cstdio>
using namespace std;

int x,y,z;
const int max=9;
int n;
int stick[3][9];
int height[3];

void draw()
{
	static int i=0;

	if(i) cout<<"Move "<<i<<endl;
	++i;
	for(int r=8;r>=0;r--)
	{
		for(int q=0;q<3;q++)
		{
			for(int i=0;i<10-stick[q][r];i++) printf(" ");
			for(int i=0;i<stick[q][r];i++) printf("#");
			if(stick[q][r])printf("#"); else printf("|");
			for(int i=0;i<stick[q][r];i++) printf("#");
			for(int i=0;i<10-stick[q][r];i++) printf(" ");

			printf("            ");

		}
		printf("\n");
	}
	printf("------------------------------------------------------------------------------------\n");
	getchar();
}

void move(int x,int z)
{
	stick[z][height[z]+1]=stick[x][height[x]];
	stick[x][height[x]]=0;
	++height[z];
	--height[x];
	draw();
}
void hanoi(int n,int x, int y,int z)
{
	if(n==1) move(x,z);
	else
	{
		hanoi(n-1,x,z,y);
		move(x,z);
		hanoi(n-1,y,x,z);
	}
}


void initialize()
{
	scanf("%d",&n);
	for(int i=0;i<3;i++) height[i]=-1;

	height[0]=n-1;
	for(int i=0;i<9;i++){ stick[0][i]=0; stick[1][i]=0;stick[2][i]=0;}
	for(int i=0;i<n;i++) stick[0][i]=n-i;
	draw();

}

int main()
{
	initialize();
	hanoi(n,0,1,2);

	return 0;
}
