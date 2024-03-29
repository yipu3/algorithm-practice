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

typedef long long ll;
using namespace std;

int a[25];
int sum[25][25];
int dp[25][15];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
		{
			sum[i][i]=a[i];
			for(int j=i+1;j<n;j++)
				sum[i][j]=sum[i][j-1]+a[j];
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			dp[i][1]=sum[0][i];
		for(int i=0;i<n;i++)
			for(int j=2;j<=m;j++)
				for(int k=0;k<i;k++)
					dp[i][j]=max(dp[i][j],dp[k][j-1]*sum[k+1][i]);
		cout<<dp[n-1][m]<<endl;
	}
	return 0;
}
