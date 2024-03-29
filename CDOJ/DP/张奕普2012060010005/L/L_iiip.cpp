#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MAXN 100005
#define MOD 10007

typedef long long ll;
using namespace std;

vector<int>  G[MAXN];
int dp[MAXN][2],num[MAXN][2];
int vis[MAXN];

void dfs(int now)
{
	dp[now][0]=0;dp[now][1]=1;
	num[now][0]=num[now][1]=1;
	for(int i=0;i<G[now].size();i++)
	{
		int temp=G[now][i];
		if(vis[temp])
			continue;
		else
		{
			vis[temp]=1;
			dfs(temp);
			dp[now][0]+=dp[temp][1];
			num[now][0]*=num[temp][1];
			num[now][0]%=MOD;
//			dp[now][1]+=min(dp[temp][0],dp[temp][1]);
			if(dp[temp][0]>dp[temp][1])
			{
				dp[now][1]+=dp[temp][1];
				num[now][1]*=num[temp][1];
				num[now][1]%=MOD;
			}
			else if(dp[temp][0]<dp[temp][1])
			{
				dp[now][1]+=dp[temp][0];
				num[now][1]*=num[temp][0];
				num[now][1]%=MOD;
			}
			else
			{
				dp[now][1]+=dp[temp][0];
				num[now][1]*=(num[temp][0]+num[temp][1]);
				num[now][1]%=MOD;
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			G[i].clear();
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		n--;
		while(n--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u-1].push_back(v-1);
			G[v-1].push_back(u-1);
		}
		vis[0]=1;
		dfs(0);
		int ans1,ans2;
		if(dp[0][0]>dp[0][1])
		{
			ans1=dp[0][1];
			ans2=num[0][1];
		}
		else if(dp[0][0]<dp[0][1])
		{
			ans1=dp[0][0];
			ans2=num[0][0];
		}
		else
		{
			ans1=dp[0][0];
			ans2=num[0][0]+num[0][1];
			ans2%=MOD;
		}
		cout<<ans1<<' '<<ans2<<endl;
	}
	return 0;
}
