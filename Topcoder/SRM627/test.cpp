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

int dp[55][55],r[55][55];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	vector<int> A;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		A.push_back(tmp);
	}
	int K;
	cin>>K;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=i;k<j;k++)
			{
				if(A[k]>A[k+1])
					r[i][j]++;
				else if(A[k]<A[k+1])
					r[i][j]--;
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<=K;j++)
			for(int k=0;k<i;k++)
				dp[i][j]=max(dp[k][j],dp[k][j-1]+r[k][i]);
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<=K;k++)
			cout<<dp[i][k]<<' ';
		cout<<endl;
	}
	int sum=0;
	for(int i=0;i<n-1;i++)
		if(A[i]>A[i+1])
			sum++;
	cout<<"sum:"<<sum<<endl;
	int ans=0;
	for(int i=0;i<=K;i++)
		ans=max(ans,dp[n-1][i]);
	cout<<sum-ans<<endl;
	return 0;
}
