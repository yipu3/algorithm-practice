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
#define MAXN 100005
#define MAXM 300005
#define INF 1000000007

typedef long long ll;
using namespace std;

int cost[MAXN];
int low[MAXN],dfn[MAXN],ins[MAXN],head[MAXN];
int ind,cnt;
vector<int> ans[MAXN];
stack<int> s;

struct edge
{
	int to,next;
}edges[MAXM];

void tarjan(int u)
{
	low[u]=dfn[u]=++ind;
	ins[u]=1;
	s.push(u);
	for(int e=head[u];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		cnt++;
		int t;
		do
		{
			t=s.top();
			s.pop();
			ins[t]=0;
			ans[cnt].push_back(t);
		}
		while(t!=u);
	}
}

int main()
{
	memset(head,-1,sizeof(head));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&cost[i]);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edges[i].next=head[u];
		edges[i].to=v;
		head[u]=i;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	ll a1=0,a2=1;
//	cout<<"cnt:"<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		int minn=INT_MAX;int cntm=0;
		for(int j=0;j<ans[i].size();j++)
		{
			if(cost[ans[i][j]]<minn)
			{
				minn=cost[ans[i][j]];
			}
		}
		for(int j=0;j<ans[i].size();j++)
			if(cost[ans[i][j]]==minn)
				cntm++;
		a1=a1+minn;
		a2=(a2*cntm)%INF;
	}
	cout<<a1<<' '<<a2<<endl;
	return 0;
}
