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
#define MAXN 200

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int vis[MAXN];
int linked[MAXN];
int G[MAXN][MAXN],tG[MAXN][MAXN];
int n,m;
//vis:点是否在增广路上 linked:j所在增广路的起点
bool find(int u){
	for(int i=1;i<=m;i++){
		if(tG[u][i]&&!vis[i]){
				vis[i]=1;
				if(!linked[i]||find(linked[i])){
					linked[i]=u;
					return true;
				}
		}
	}
	return false;
}

int count(){
	memset(linked,0,sizeof(linked));
	int ret=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(find(i)){
			ret++;
		}
	}
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d%d",&n,&m);
		char tmp[MAXN];
		for(int i=1;i<=n;i++){
			scanf("%s",tmp);
			for(int j=0;j<m;j++){
				if(tmp[j]=='1'){
					G[i][j+1]=1;
				}else
					G[i][j+1]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(G[i][j]){
					int cnta=0,cntb=0;
					for(int k=1;k<=n;k++)
						if(G[k][j])
							cnta++;
					for(int l=1;l<=m;l++)
						if(G[i][l])
							cntb++;
					for(int k=1;k<=n;k++)
						for(int l=1;l<=m;l++){
							if(G[k][j]&&G[i][l])
								tG[k][l]=1-G[k][l];
							else
								tG[k][l]=0;
						}
					ans=max(ans,cnta+cntb-count());
				}
		printf("Case %d: %d\n",cas,ans);
	}
	return 0;
}
