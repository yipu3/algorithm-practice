#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<sstream>
#include<string>
#define INF 1000000

typedef long long ll;
using namespace std;

int maze[15][15];
int vis[15][15];
int hav[15][15];
int ti[15][15];
int dist[105][105];
int ans[3];
int dx[4]={
	0,0,1,-1
};
int dy[4]={
	1,-1,0,0
};
int n,m,ta,c;

struct node
{
	int x,y,ta;
};

void dfs(int x,int y)
{
	vis[x][y]=1;
	hav[x][y]=c;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<n&&tx>=0&&ty<m&&ty>=0&&!vis[tx][ty]&&maze[tx][ty]=='#')
			dfs(tx,ty);
	}
}

void bfs2(int x,int y)
{
	queue<node> q;
	node s;
	s.x=x;s.y=y;s.ta=0;
	q.push(s);
	vis[s.x][s.y]=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			node nn;
			nn.x=t.x+dx[i];nn.y=t.y+dy[i],nn.ta=t.ta+1;
			if(nn.x<n&&nn.x>=0&&nn.y<m&&nn.y>=0&&!vis[nn.x][nn.y]&&maze[nn.x][nn.y]=='#')
			{
				vis[nn.x][nn.y]=1;
				ta=max(ta,nn.ta);
				q.push(nn);
			}
		}
	}
}

int bfs1(int x,int y,int r,int s)
{
	queue<node> q;
	node s1,s2;
	s1.x=x;s1.y=y;s1.ta=0;
	s2.x=r;s2.y=s;s2.ta=0;
	q.push(s1);q.push(s2);
	vis[s1.x][s1.y]=vis[s2.x][s2.y]=1;
	dist[x][y]=dist[r][s]=0;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			node nn;
			nn.x=t.x+dx[i];nn.y=t.y+dy[i],nn.ta=t.ta+1;
			if(nn.x<n&&nn.x>=0&&nn.y<m&&nn.y>=0&&!vis[nn.x][nn.y]&&maze[nn.x][nn.y]=='#')
			{
				vis[nn.x][nn.y]=1;
				if(dist[nn.x][nn.y]>t.ta+1)
					dist[nn.x][nn.y]=t.ta+1;
				q.push(nn);
			}
		}
	}
	int tmp=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(hav[i][j])
				tmp=max(tmp,dist[i][j]);
	return tmp;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		memset(ans,0,sizeof(ans));
		memset(hav,0,sizeof(hav));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			char tmp[15];
			scanf("%s",tmp);
			for(int j=0;j<m;j++)
				maze[i][j]=tmp[j];
		}
		c=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(!vis[i][j]&&maze[i][j]=='#')
				{
					c++;
					dfs(i,j);
				}
		int ans;
		if(c>2)
		{
			printf("Case %d: -1\n",cas);
			continue;
		}
		if(c==1)
		{
			ans=1000000;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					for(int r=0;r<n;r++)
						for(int s=0;s<m;s++)
							if(hav[i][j]==1&&hav[r][s]==1)
							{
								memset(vis,0,sizeof(vis));
								for(int l=0;l<n;l++)
								{
									for(int d=0;d<m;d++)
										dist[l][d]=INF;
								}
								ans=min(ans,bfs1(i,j,r,s));
							}
			printf("Case %d: %d\n",cas,ans);
		}
		if(c==2)
		{
			int t1=100000,t2=100000;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
				{
					if(hav[i][j]==1)
					{
						ta=0;
						memset(vis,0,sizeof(vis));
						bfs2(i,j);
						t1=min(t1,ta);
					}
					if(hav[i][j]==2)
					{
						ta=0;
						memset(vis,0,sizeof(vis));
						bfs2(i,j);
						t2=min(t2,ta);
					}
				}
			ans=max(t1,t2);
			printf("Case %d: %d\n",cas,ans);
			continue;
		}
	}
	return 0;
}
