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
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector< pair<int,int> > alpha[26];

int dp[105][105];

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		string s;
		int b;
		cin>>s>>b;
		for(int i=0;i<26;i++){
			int q;
			scanf("%d",&q);
			alpha[i].clear();
			while(q--){
				int p,c;
				scanf("%d%d",&p,&c);
				pair<int,int> tmp=make_pair(p,c);
				alpha[i].push_back(tmp);
			}
		}
		//dp[b][j];
		int n=s.size();
		for(int i=0;i<=b;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=INF;
		for(int i=0;i<n;i++){
			int tmp=s[i]-'a';
			int ret=0;
			for(int j=0;j<alpha[tmp].size();j++){
				if(1%alpha[tmp][j].first==0){
					ret+=1/alpha[tmp][j].first*alpha[tmp][j].second;
				}
			}
			dp[1][i]=ret;
		}
		for(int i=2;i<=b;i++){
			for(int j=0;j<n;j++){
				int tmp=s[j]-'a';
				int ret=0;
				int cnt=0;
				for(int k=0;k<alpha[tmp].size();k++){
					if(i%alpha[tmp][k].first==0){
						cnt++;
						ret+=i/alpha[tmp][k].first*alpha[tmp][k].second;
					}
				}
				for(int k=0;k<j;k++)
					dp[i][j]=min(dp[i][j],dp[i-1][k]);
				dp[i][j]+=ret;
			}
		}
		int ans=INF;
		for(int i=0;i<n;i++){
			ans=min(ans,dp[b][i]);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
