#include<cstdio>
#include<string>
#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>

using namespace std;
typedef pair<int,int> pii;

const int INF=1000000000;
const int MAXN=5005;
const int MAXM=200005;

int head[MAXN],d[MAXN],d2[MAXN];

struct edge{
	int to,next,w;
}edges[MAXM];
int em;

void addedge(int u,int v,int w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	head[u]=em++;
}

priority_queue< pii,vector<pii>,greater<pii> > q;

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	memset(head,-1,sizeof(head));
	em=0;
	while(r--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u-1,v-1,w);
		addedge(v-1,u-1,w);
	}
	fill(d,d+n,INF);
	fill(d2,d2+n,INF);
	q.push(pii(d[0]=0,0));
	while(!q.empty()){
		pii now=q.top();q.pop();
		int u=now.second,td=now.first;
		for(int e=head[u];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(d[v]>td+edges[e].w){
				d[v]=edges[e].w+td;
				q.push(pii(d[v],v));
			}
			if(d2[v]>edges[e].w+td&&edges[e].w+td>d[v]){
				d2[v]=edges[e].w+td;
				q.push(pii(d2[v],v));
			}
		}
	}
	printf("%d",d2[n-1]);
}
