/*
ID: firstaw1
PROG: numtri
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
#define MAXR 1005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int dp[MAXR][MAXR],a[MAXR][MAXR];
int r;

int dfs(int x,int y){
	if(dp[x][y]!=-1)
		return dp[x][y];
	if(x==r-1)
		return dp[x][y]=a[x][y];
	else
		return dp[x][y]=max(dfs(x+1,y),dfs(x+1,y+1))+a[x][y];
}

int main(){
	freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
	scanf("%d",&r);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<r;i++)
		for(int j=0;j<=i;j++)
			scanf("%d",&a[i][j]);
	printf("%d\n",dfs(0,0));
	return 0;
}
