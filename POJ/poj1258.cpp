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
#define MAXN 105

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int f[MAXN],grid[MAXN][MAXN];
struct edge{
	int from,to,w;
};
vector<edge> edges;

bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}

int find(int x){
	if(f[x]==x)
		return f[x];
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}


int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			f[i]=i;
		edges.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				int tmp;
				scanf("%d",&tmp);
				if(i<j){
					edge t;
					t.from=i;t.to=j;t.w=tmp;
					edges.push_back(t);
				}
			}
		sort(edges.begin(),edges.end(),cmp);
		int ans=0;
		for(int i=0;i<edges.size();i++){
			int u=edges[i].from,v=edges[i].to;
			int x=find(u),y=find(v);
			if(x!=y){
				f[x]=y;
				ans+=edges[i].w;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
