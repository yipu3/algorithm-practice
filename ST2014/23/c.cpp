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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	dfs(0);
	if(vis[n-1]==0){
		cout<<-1;
		return 0;
	}
	for(int i=0;i<n;i++)
		dp[i][0]=dp[i][1]=INF;
	queue<int> q;
	fill(inq,inq+n,0);
	q.push(0);
	inq[0]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		inq[now]=0;
		for(int e=head[now];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(edges[e].w<dp[now][1]&&dp[v][1]>dp[now][1]){
				dp[v][1]=dp[now][1];
				dp[v][0]=dp[now][0];
			}else if()
		}
	}
	return 0;
}
