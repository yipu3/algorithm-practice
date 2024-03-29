#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>

typedef long long ll;
using namespace std;

int head[150],vis[150],em;

struct edge
{
	int to,next,rev,cap;
}edges[250];

void addedge(int u,int v)
{
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].cap=1;
	edges[em].rev=em+1;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	edges[em].cap=1;
	edges[em].rev=em-1;
	head[v]=em++;
}

int dfs(int s,int t,int f)
{
	if(s==t)
		return f;
	vis[s]=1;
	for(int e=head[s];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(!vis[v]&&edges[e].cap>0)
		{
			int d=dfs(v,t,min(f,edges[e].cap));
			if(d>0)
			{
				edges[e].cap-=d;
				edges[edges[e].rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int h,w;
	scanf("%d%d",&h,&w);
	if(h*w%2!=0)
		printf("0\n");
	memset(head,-1,sizeof(head));
	for(int i=1;i<=h*w;i++)
	{
		int x=i/h,y=i%h;
		if(i%2==1)
		{
			addedge(0,i);
			if(x+1<=w)
				addedge(i,(x+1)*h+y);
			if(x-1>=1)
				addedge(i,(x-1)*h+y);
			if(y+1<=h)
				addedge(i,x*h+y+1);
			if(y-1>=1)
				addedge(i,x*h+y-1);
		}
		else
			addedge(i,h*w+1);
	}
	int ans=0;
	while(1)
	{
		memset(vis,0,sizeof(vis));
		int f=dfs(0,h*w+1,2);
		if(f>0)
			ans+=f;
		else
			break;
	}
	printf("%d\n",ans);
	return 0;
}
