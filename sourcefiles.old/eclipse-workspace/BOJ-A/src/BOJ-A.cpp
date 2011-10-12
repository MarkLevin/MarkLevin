#include "stdio.h"
int nowx,nowy;
int m,n;
bool maze[30][30];
bool condition[30][30];
bool path[30][30];
int p,sum;
int x1,y1;
void dfs (int depth)
{
     if(depth==p-1)                  sum++;
	 else {if((nowx+1<m)&&(maze[nowy][nowx+1]==true)&&(condition[nowy][nowx+1]==false)&&(path[nowy][nowx+1]))
    {
        condition[nowy][nowx+1]=true ;
        path[nowy][nowx+1]=false;
        nowx=nowx+1;nowy=nowy;
        dfs(depth+1);
        path[nowy][nowx+1]=true;
        nowx=nowx-1;nowy=nowy;
        condition[nowy][nowx+1]=false;
    }
    if((nowx-1>=0)&&(maze[nowy][nowx-1]==true)&&(condition[nowy][nowx-1]==false)&&path[nowy][nowx-1])
    {
        condition[nowy][nowx-1]=true ;
        path[nowy][nowx-1]=false;
        nowx=nowx-1;nowy=nowy;
        dfs(depth+1);
        path[nowy][nowx-1]=true;
        nowx=nowx+1;nowy=nowy;
        condition[nowy][nowx-1]=false;
    }
    if((nowy+1< n)&&(maze[nowy+1][nowx]==true)&&(condition[nowy+1][nowx]==false)&&path[nowy+1][nowx])
    {
        condition[nowy+1][nowx]=true;
        path[nowy+1][nowx]=false;
        nowx=nowx;nowy=nowy+1;
        dfs(depth+1);
        nowx=nowx;nowy=nowy-1;
        path[nowy+1][nowx]=true;
        condition[nowy+1][nowx]=false;
    }
    if((nowy-1>=0)&&(maze[nowy-1][nowx]==true)&&(condition[nowy-1][nowx]==false)&&path[nowy-1][nowx])
    {
        condition[nowy-1][nowx]=true;
        nowx=nowx;nowy=nowy-1;
        path[nowy-1][nowx]=false;
        dfs(depth+1);
        nowx=nowx;nowy=nowy+1;
        path[nowy-1][nowx]=true;
        condition[nowy-1][nowx]=false;
    }}
}
int main()
{
	while(scanf("%d",&m)!=EOF){
		scanf("%d%d",&n,&p);
	sum=0;
    for(int w=0;w<n;w++)
    {
    	for(int t=0;t<m;t++)
    	{
    		x1=t;y1=w;

    		for(int i=0;i<n;i++)
    			for(int j=0;j<m;j++)
    			{	maze[i][j] =1;path[i][j]=1;condition[i][j]=false;}
				condition[x1][y1]=false;
				path[w][t]=false;
			if((x1+1< m)&&maze[y1][x1+1]&&path[y1][x1+1])
			{
				condition[y1][x1+1]=true ;
				path[y1][x1+1]=false;
				nowx=x1+1;nowy=y1;
				dfs(1);
				path[y1][x1+1]=true;
				condition[y1][x1+1]=false;
			}
			if((x1-1>=0)&&(maze[y1][x1-1]==true)&&path[y1][x1-1])
			{
				condition[y1][x1-1]=true ;
				nowx=x1-1;nowy=y1;
				path[y1][x1-1]=false;
				dfs(1);
				path[y1][x1-1]=true;
				condition[y1][x1-1]=false;
			}
			if((y1+1< n)&&(maze[y1+1][x1]==true)&&path[y1+1][x1])
			{
				condition[y1+1][x1]=true;
				nowx=x1;nowy=y1+1;
				path[y1+1][x1]=false;
				dfs(1);
				condition[y1+1][x1]=false;
				path[y1+1][x1]=true;
			}
			if((y1-1>=0)&&(maze[y1-1][x1]==true)&&path[y1-1][x1])
			{
				condition[y1-1][x1]=true;
				path[y1-1][x1]=false;
				nowx=x1;nowy=y1-1;
				dfs(1);
				path[y1-1][x1]=true;
				condition[y1-1][x1]=false;
			}
    	}}
		printf("%d\n",sum);
	}
    return 0;
	}

