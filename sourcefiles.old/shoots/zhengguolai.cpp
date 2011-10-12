#include <fstream>
using namespace std;
int main()
{
	ifstream in("maze.in",ios::in);
	ofstream out("maze2.in",ios::out);
	int b;
	in>>b;
	in>>b;
	in>>b;
	in>>b;
	in>>b;
	in>>b;
	for(int i=1;i<200;i++)
	{
		int a;
		in>>a;
		if(a==1) out<<"0 ";
		else  out<<"1 ";
		if(i%20==0&&(i!=0)) out<<endl;
	}
}
