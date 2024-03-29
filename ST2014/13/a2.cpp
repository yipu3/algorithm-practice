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
#define MAXN 55

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int vis[(1<<20)];
int a[MAXN][MAXN];
int ans[MAXN];
int hash[MAXN];

int n;

void dfs(int x){
	vis[x]=1;
	bool find=false;
	for(int i=0;i<n;i++){
		if((x&(1<<i))==0){
			int ha=0;
			for(int j=0;j<n;j++)
				if((x&(1<<j))==0&&i!=j)
					ha+=a[i][j];
			if(ha>0){
				if(!vis[x|1<<i]){
					dfs(x|1<<i);
					find=true;
				}
			}
		}
	}
	int now,cnt=0;
	if(!find)
		for(int i=0;i<n;i++)
			if((x&(1<<i))==0){
				cnt++;
				now=i;
			}
	if(cnt==1)
		hash[now]=1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		fill(hash,hash+n,0);
		fill(vis,vis+(1<<20),0);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		dfs(0);
		int cnt=0;
		for(int i=0;i<n;i++)
			if(hash[i])
				ans[cnt++]=i;
		if(cnt==0){
			printf("0\n");
		}else{
			sort(ans,ans+cnt);
			printf("%d",ans[0]+1);
			for(int i=1;i<cnt;i++)
				printf(" %d",ans[i]+1);
			printf("\n");
		}
	}
	return 0;
}
