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
#define MAXN 10005
#define MAXM 100005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct node{
	int out,in,ind;
}ver[MAXN];

int vis[MAXN],head[MAXN];
int em;

struct edge{
	int to,next;
}edges[MAXM];

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

void dfs(int u){
	vis[u]=1;
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!vis[v]){
			dfs(v);
		}
	}
}

bool cmp(const node &a,const node &b){
	if(a.in!=b.in){
		return a.in<b.in;
	}else
		return a.out>b.out;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));
		em=0;
		for(int i=1;i<=n;i++)
			ver[i].ind=i;
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			ver[u].out++;
			ver[v].in++;
		}
		int ans=0;
		sort(ver+1,ver+n+1,cmp);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			if(!vis[ver[i].ind]){
				dfs(ver[i].ind);
				ans++;
			}
		printf("Case %d: %d\n",cas,ans);
	}
	return 0;
}
