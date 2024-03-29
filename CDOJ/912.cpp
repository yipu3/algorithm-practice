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
#define MAXN 500010
#define MAXM 500010

typedef long long ll;
using namespace std;

int n,em,q,ind,head[MAXN],id[MAXN],vs[MAXN],depth[MAXN],endn[MAXN],c[MAXN];
int vis[MAXN];

struct edge
{
	int u,v,next,w;
}edges[MAXM];

void dfs(int u,int p,int d)
{
	id[u]=ind;
	vs[ind]=u;
	depth[ind++]=d;
	for(int e=head[u];e!=-1;e=edges[e].next)
	{
		int v=edges[e].v;
		if(v!=p)
		{
			dfs(v,u,d+edges[e].w);
			vs[ind]=u;
			depth[ind++]=d;
		}
	}
	endn[id[u]]=ind-1; //-1
}

int dp[MAXN][30];

void rmq_init()
{
	for(int i=1;i<=ind;i++)
		dp[i][0]=i;
	int m=floor(log(ind*1.0)/log(2.0));
	for(int j=1;j<=m;j++)
		for(int i=1;i<=ind;i++)
			dp[i][j]=depth[dp[i][j-1]]<depth[dp[i+(1<<(j-1))][j-1]]? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
}

int solve(int l,int r)
{
	int k=floor(log((double)r-l+1)/log(2.0));
	return depth[dp[l][k]]<depth[dp[r-(1<<k)+1][k]]? dp[l][k]:dp[r-(1<<k)+1][k];
}

int LCA(int a,int b)
{
	if(id[a]>id[b])
	{
		int t=a;
		a=b;
		b=t;
	}
	return solve(id[a],id[b]);
}

int lowbit(int x)
{
	return x&(-x);
}

int sum(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}

void add(int x,int d)
{
    while(x<=ind)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

int main()
{
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	em=1;ind=1;
	for(int i=1;i<=n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edges[em].next=head[u];edges[em].w=w;edges[em].u=u;edges[em].v=v;
		head[u]=em++;
		edges[em].next=head[v];edges[em].w=w;edges[em].u=v;edges[em].v=u;
		head[v]=em++;
	}
	dfs(1,-1,0);
	rmq_init();
/*	for(int i=1;i<=9;i++)
		cout<<vs[i]<<' ';
	cout<<endl;
	for(int i=1;i<=9;i++)
		cout<<depth[i]<<' ';
	cout<<endl;
	for(int i=1;i<=5;i++)
		cout<<id[i]<<' ';
	cout<<endl;*/
	scanf("%d",&q);
	while(q--)
	{
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b);
		if(op==1)
		{
			int lca=LCA(a,b);
//			cout<<"LCA:"<<lca<<endl;
//			cout<<"lca:"<<lca<<endl;
			int ans=depth[id[a]]+sum(id[a])+depth[id[b]]+sum(id[b])-2*(depth[lca]+sum(lca));
			printf("%d\n",ans);
		}
		if(op==2)
		{
			edge e=edges[a*2];
			int u=e.u;
			int v=e.v;
			int w=e.w;
			int t=max(id[u],id[v]);
//			cout<<t<<' '<<end[t]<<endl;
			add(t,b-w);
			add(endn[t]+1,w-b);
//			for(int i=1;i<=5;i++)
//				cout<<i<<':'<<depth[i]<<' ';
//			cout<<endl;
		}
	}
	return 0;
}
