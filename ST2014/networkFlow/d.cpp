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
#define MAX_V 20100
#define INF 1000000000
#define MAX_E 1000005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int level[MAX_V],iter[MAX_V],head[MAX_V];

struct edge{
	int to,cap,next,rev;
}edges[MAX_E];
int em,n,m;

void addedge(int u,int v,int cap){
	edges[em].to=v;
	edges[em].next=head[u];
	edges[em].rev=em+1;
	edges[em].cap=cap;
	head[u]=em++;
	edges[em].to=u;
	edges[em].next=head[v];
	edges[em].cap=0;
	edges[em].rev=em-1;
	head[v]=em++;
}

void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> q;
	level[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int e=head[u];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(edges[e].cap>0&&level[v]<0){
				level[v]=level[u]+1;
				q.push(v);
			}
		}
	}
}

int dfs(int s,int t,int f){
	if(s==t)
		return f;
	for(int &e=iter[s];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(edges[e].cap>0&&level[s]<level[v]){
			int d=dfs(v,t,min(f,edges[e].cap));
			if(d>0){
				edges[e].cap-=d;
				edges[edges[e].rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)
			return flow;
		for(int i=0;i<n+2;i++)
			iter[i]=head[i];
		int f;
		while((f=dfs(s,t,INF))>0)
			flow+=f;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addedge(0,i,a);
		addedge(i,n+1,b);
	}
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	int ans=max_flow(0,n+1);
	printf("%d",ans);
	return 0;
}
