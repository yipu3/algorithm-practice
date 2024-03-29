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
using namespace std;

int dp[MAXN][MAXN],T1[MAXN],T2[MAXN],T3[MAXN],F1[MAXN],F2[MAXN];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d%d",&T1[i],&T2[i],&T3[i],&F1[i],&F2[i]);
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				dp[i][j]=MAXN*MAXN;
		dp[0][m]=0;
		for(int i=0;i<n;i++)
			for(int j=m;j>=0;j--){
				if(dp[i][j]==MAXN*MAXN)
					continue;
				if(j>=F1[i]){
					dp[i+1][j-F1[i]]=min(dp[i+1][j-F1[i]],dp[i][j]+T1[i]);
				}
				dp[i+1][min(m,j+F2[i])]=min(dp[i+1][min(m,j+F2[i])],dp[i][j]+T3[i]);
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+T2[i]);
			}
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<=m;j++)
//				cout<<dp[i][j]<<' ';
//			cout<<endl;
//		}
		int ans=INT_MAX,jj;
		for(int i=0;i<=m;i++)
			if(dp[n][i]<ans&&dp[n][i]!=MAXN*MAXN){
				ans=dp[n][i];
			}
		printf("%d\n",ans);
	}
	return 0;
}
