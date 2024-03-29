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
#define INF 23

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
		int n,ans;

int mm[22][22];
int cnt[22];
int hh[1<<22];
int vis[22];

int dfs(int x,int cnt,int hash){
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(mm[x][i]==1&&((hash&(1<<i))==0))
			hash|=(1<<i);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			dfs(i,cnt+1,hash);
		}
	if(hash==((1<<(n+1))-1)){
		ans=min(ans,cnt);
	}
	vis[x]=0;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(hh,0,sizeof(hh));
		memset(mm,0,sizeof(mm));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				int tmp;
				scanf("%d",&tmp);
				if(!mm[i][tmp]){
					mm[i][tmp]=1;
				}
				if(!mm[tmp][i]){
					mm[tmp][i]=1;
				}
			}
			mm[i][i]=1;
		}
		ans=INF;
		for(int i=1;i<=n;i++){
			dfs(i,1,0);
		}
		printf("%d\n",ans);
	}
	return 0;
}
