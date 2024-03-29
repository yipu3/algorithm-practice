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

int head[10005],low[10005],dfn[10005],vis[10005],ind;

struct edge
{
	int to,next;
}edges[100005];

struct amount
{
	int num,ans;
}amo[10005];

void tarjan(int x,int fa)
{
	low[x]=dfn[x]=++ind;
	for(int e=head[x];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(!dfn[v])
		{
			tarjan(v,x);
			if(low[v]>=dfn[x])
				amo[x].ans++;
			low[x]=min(low[x],low[v]);
		}
		else if(v!=fa)
			low[x]=min(low[x],dfn[v]);
	}
}


bool cmp(const amount &a,const amount &b)
{
	if(a.ans>b.ans)
		return 1;
	else if(a.ans==b.ans)
		return a.num<b.num;
	else
		return 0;
}

int main()
{
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		for(int i=0;i<n;i++)
		{
			amo[i].num=0;
			amo[i].ans=0;
		}
		ind=0;
		int em=0;
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			edges[em].next=head[u];
			edges[em].to=v;
			head[u]=em++;
			edges[em].next=head[v];
			edges[em].to=u;
			head[v]=em++;
		}
		tarjan(0,-1);
		amo[0].num=0;
		for(int i=1;i<n;i++)
		{
			amo[i].ans++;
			amo[i].num=i;
		}
		sort(amo,amo+n,cmp);
		for(int i=0;i<k;i++)
			printf("%d %d\n",amo[i].num,amo[i].ans);
		printf("\n");
	}
	return 0;
}
