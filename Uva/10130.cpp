#include<iostream>
#include<cstring>
using namespace std;
int dp[1005][40];
int p[1005],w[1005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>p[i]>>w[i];
		int g,sum=0;
		cin>>g;
		while(g--)
		{
			int mw;
			cin>>mw;
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
				for(int j=0;j<=mw;j++)
				{
					dp[i][j]=dp[i-1][j];
					if(j>=w[i])
						if(dp[i][j]<dp[i-1][j-w[i]]+p[i])
							dp[i][j]=dp[i-1][j-w[i]]+p[i];
				}
			sum+=dp[n][mw];
		}
		cout<<sum<<endl;
	}
	return 0;
}
