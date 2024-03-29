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
#define MAXN 10010
#define MAXM 100010

typedef long long ll;
using namespace std;

int cc,ind,cut[MAXN],head[MAXN],dfn[MAXN],low[MAXN],vis[MAXN];

struct edge
{
	int to,next;
}edges[MAXM];

struct an
{
	int pos,mx;
}cnt[MAXN];

void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++ind;
	int temp=0;
	for(int e=head[x];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(v!=fa)
		{
			if(!dfn[v])
			{
				tarjan(v,x);
				if(low[v]>=dfn[x])
					cnt[x].mx++;
				low[x]=min(low[x],low[v]);
			}
			low[x]=min(low[x],low[v]);
		}
	}
}

void dfs(int x)
{
	vis[x]=1;
	for(int e=head[x];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(!vis[v]&&v!=cc)
			dfs(v);
	}
}

bool cmp(const an &a,const an &b)
{
	return a.mx>b.mx;
}

int main()
{
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		memset(head,-1,sizeof(head));
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		memset(cut,0,sizeof(cut));
		ind=0;
		int cn=0,em=0;
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			edges[em].to=v;
			edges[em].next=head[u];
			head[u]=em++;
			edges[em].to=u;
			edges[em].next=head[v];
			head[v]=em++;
		}
		tarjan(0,-1);
//		cout<<1<<endl;
		sort(cnt,cnt+n,cmp);
		for(int i=0;i<k;i++)
			printf("%d %d\n",cnt[i].pos,cnt[i].mx);
	}
	return 0;
}
