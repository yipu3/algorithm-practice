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
#define INF 100005

typedef long long ll;
using namespace std;

vector<int> s1;
vector<int> s2[100005];
int dp[100005][305];
int mark[100005][305];

int main()
{
	int n,m,s,e;
	scanf("%d%d%d%d",&n,&m,&s,&e);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		s1.push_back(temp);
	}
	for(int i=0;i<m;i++)
	{
		int temp;
		scanf("%d",&temp);
		s2[temp].push_back((i+1));
	}
	int max=s/e;
	for(int i=0;i<=max;i++)
		dp[0][i]=INF;
	for(int i=0;i<n;i++)
		for(int j=0;j<=max;j++)
		{
			if(j>i+1||j==0)
			{
				dp[i+1][j]=INF;
				continue;
			}
			int pos=dp[i][j-1];
			if(pos==INF)
			{
				dp[i+1][j]=dp[i][j];
				mark[i+1][j]=mark[i][j];
				continue;
			}
			int temp=lower_bound(s2[s1[i]].begin(),s2[s1[i]].end(),pos)-s2[s1[i]].begin();
			if(temp==s2[s1[i]].size())
			{
				dp[i+1][j]=dp[i][j];
				mark[i+1][j]=mark[i][j];
				continue;
			}
			else
			{
				if(s2[s1[i]][temp]+1>=dp[i][j])
				{
					dp[i+1][j]=dp[i][j];
					mark[i+1][j]=mark[i][j];
				}
				else
				{
					dp[i+1][j]=s2[s1[i]][temp]+1;
					mark[i+1][j]=i+1;
				}
			}
		}
	cout<<dp[1][1]<<endl;
	for(int j=max;j>=1;j++)
	{
		if(mark[n][j]==0)
			continue;
		else
		{
			if(dp[n][j]+mark[n][j]+j*e<=s)
			{
				printf("%d\n",j);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}
