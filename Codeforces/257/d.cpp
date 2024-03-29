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
#define MAXN 100005
#define INF 10000000

typedef long long ll;
using namespace std;

struct edge{
	int to;int w;int mark;
};

struct node{
	int d,ne,to;
};

struct cmp
{
	bool operator() (const node &a,const node &b)
	{
		if(a.d>b.d)
			return 1;
		else
			return 0;
	}
};

vector<edge> G[MAXN];

int d[MAXN],ee[MAXN];

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		edge tmp;
		tmp.to=v;
		tmp.w=w;
		tmp.mark=0;
		G[u].push_back(tmp);
		tmp.to=u;
		tmp.w=w;
		tmp.mark=0;
		G[v].push_back(tmp);
	}
	int em=1;
	while(k--)
	{
		int v,w;
		cin>>v>>w;
		edge tmp;
		tmp.to=v;
		tmp.w=w;
		tmp.mark=em;
		G[1].push_back(tmp);
		tmp.to=1;
		tmp.w=w;
		tmp.mark=em++;
		G[v].push_back(tmp);
	}
	priority_queue<node, vector<node>, cmp > que;
	for(int i=1;i<=n;i++){
		d[i]=INF;
		ee[i]=0;
	}
	d[1]=0;
	node s;
	s.d=0;
	s.to=1;
	s.ne=0;
	que.push(s);
	while(!que.empty()){
		node p=que.top();que.pop();
		int v=p.to;
		if(d[v]<p.d)
			continue;
		ee[v]=p.ne;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.w){
				d[e.to]=d[v]+e.w;
				node nn;
				nn.to=e.to;
				nn.d=d[v]+e.w;
				nn.ne=e.mark;
				que.push(nn);
			}
		}
	}
	set<int> ss;
	for(int i=0;i<n;i++)
		if(ee[i]!=0)
			ss.insert(i);
	int cnt=0;
	for(int i=1;i<em;i++)
		if(ss.count(i))
			cnt++;
	cout<<k-cnt<<endl;
	return 0;
}
