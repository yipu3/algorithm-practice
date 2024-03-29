/*
ID: firstaw1
PROG: milk3
LANG: C++
*/
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

bool vis[21][21][21],mark[21];
int maxx[3],t[3];
int ans[21];

void pour(int a,int b){
	int resb=maxx[b]-t[b];
	if(resb<t[a]){
		t[a]-=resb;
		t[b]=maxx[b];
	}else{
		t[b]+=t[a];
		t[a]=0;
	}
}

int cnt;

void dfs(int na,int nb,int nc){
	if(vis[na][nb][nc])
		return;
	else
		vis[na][nb][nc]=true;
	if(na==0&&!mark[nc]){
		ans[cnt++]=nc;
		mark[nc]=true;
	}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			t[0]=na;t[1]=nb;t[2]=nc;
			if(i!=j){
				pour(i,j);
				dfs(t[0],t[1],t[2]);
			}
		}
}

int main(){
	freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
	scanf("%d%d%d",&maxx[0],&maxx[1],&maxx[2]);
	dfs(0,0,maxx[2]);
	sort(ans,ans+cnt);
	printf("%d",ans[0]);
	for(int i=1;i<cnt;i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
