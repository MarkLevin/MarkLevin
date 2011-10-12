#include <iostream>
using namespace std;
const int MAXLEN=10000;
const int MAXSTEP=10000;
const int MAXBESTSOL=500;
int pathx[MAXSTEP],pathy[MAXSTEP];
int x1,x2,y1,y2;
int nowx,nowy;
int m,n,minl=30000000;
int bestnum=1;
bool maze[MAXLEN][MAXLEN];
bool condition[MAXLEN][MAXLEN];
int bestcondition[MAXBESTSOL][2][MAXSTEP];
void dfs (int depth)
{
     if(depth==4)
     {                         cout<<"("<<x1+1      <<","<<y1+1      <<") -> ";
                                   
                               for(int i=0;i<depth;i++)
                               {

                                       if(i!=depth-1)
                                       cout<<"("<<pathx[i]+1<<","<<pathy[i]+1<<") -> ";
                                       else
                                       cout<<"("<<pathx[i]+1<<","<<pathy[i]+1<<")";
                               }
                               cout<<endl;
                               if(depth<=minl) 
                               {
                                             minl=depth;
                                             for(int i=0;i<minl;i++)
                                             {
                                                     bestcondition[bestnum-1][0][i]=pathx[i];
                                                     bestcondition[bestnum-1][1][i]=pathy[i];
                                             }                           
                               }
                               if(depth==minl) ++bestnum;
     }
     if((nowx+1< m)&&(maze[nowy][nowx+1]==true)&&(condition[nowy][nowx+1]==false))
    {
        condition[nowy][nowx+1]=true ;
        nowx=nowx+1;nowy=nowy;
        pathx[depth]=nowx;
        pathy[depth]=nowy;
        dfs(depth+1);
        nowx=nowx-1;nowy=nowy;
        condition[nowy][nowx+1]=false;
    }
    if((nowx-1>=0)&&(maze[nowy][nowx-1]==true)&&(condition[nowy][nowx-1]==false))
    {
        condition[nowy][nowx-1]=true ;
        nowx=nowx-1;nowy=nowy;
        pathx[depth]=nowx;
        pathy[depth]=nowy;
        dfs(depth+1);
        nowx=nowx+1;nowy=nowy;
        condition[nowy][nowx-1]=false;
    }
    if((nowy+1< n)&&(maze[nowy+1][nowx]==true)&&(condition[nowy+1][nowx]==false))
    {
        condition[nowy+1][nowx]=true;
        nowx=nowx;nowy=nowy+1;
        pathx[depth]=nowx;
        pathy[depth]=nowy;
        dfs(depth+1);
        nowx=nowx;nowy=nowy-1;
        condition[nowy+1][nowx]=false;
    }
    if((nowy-1>=0)&&(maze[nowy-1][nowx]==true)&&(condition[nowy-1][nowx]==false))
    {
        condition[nowy-1][nowx]=true;
        nowx=nowx;nowy=nowy-1;
        pathx[depth]=nowx;
        pathy[depth]=nowy;
        dfs(depth+1);
        nowx=nowx;nowy=nowy+1;
        condition[nowy-1][nowx]=false;
    }
}
int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
            maze[i][j] =1;
      }
    x1--;y1--;
    pathx[0]=x1;pathy[0]=y1;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) condition[i][j]=false;                                                                                
    condition[x1][y1]=true;
    if((x1+1< m)&&(maze[y1][x1+1]==true))
    {
        condition[y1][x1+1]=true ;
        nowx=x1+1;nowy=y1;
        pathx[0]=nowx;pathy[0]=nowy;
        dfs(1);
        condition[y1][x1+1]=false;
    }
    if((x1-1>=0)&&(maze[y1][x1-1]==true))
    {
        condition[y1][x1-1]=true ;
        nowx=x1-1;nowy=y1;
        pathx[0]=nowx;pathy[0]=nowy;
        dfs(1);
        condition[y1][x1-1]=false;
    }
    if((y1+1< n)&&(maze[y1+1][x1]==true))
    {
        condition[y1+1][x1]=true;
        nowx=x1;nowy=y1+1;
        pathx[0]=nowx;pathy[0]=nowy;
        dfs(1);
        condition[y1+1][x1]=false;
    }
    if((y1-1>=0)&&(maze[y1-1][x1]==true))
    {
        condition[y1-1][x1]=true;
        nowx=x1;nowy=y1-1;
        pathx[0]=nowx;pathy[0]=nowy;
        dfs(1);
        condition[y1-1][x1]=false;
    }
    for(int w=0;w<3;w++)
    {
    cout<<"("<<x1+1      <<","<<y1+1      <<") -> ";
	}
    return 0;
}
