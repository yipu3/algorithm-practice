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

int m,n;
ll minn;
ll G[20][110];
ll dp[20][110];
int fa[20][110];
int dir[20*110];

void init()
{
	for(int i=0;i<m;i++)
		for(int j=n-1;j>=0;j--)
			cin>>G[i][j];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=LLONG_MAX;
	for(int i=0;i<m;i++)
		dp[i][0]=G[i][0];
	for(int i=0;i<m;i++)
		fa[i][0]=i*n;
	memset(dir,0,sizeof(dir));
}

void print_path(int x,int y)
{
	int fx=fa[x][y]/n;
	int fy=fa[x][y]%n;
	if( fx!=x || fy!=y)
	{
		print_path(fx,fy);
	}
	cout<<x+1<<' ';
}

int l;
void solve()
{
	for(int j=0;j<n-1;j++)
		for(int i=0;i<m;i++)
		{
			if(dp[(i+m-1)%m][j+1]>dp[i][j]+G[(i+m-1)%m][j+1])
			{
				dp[(i+m-1)%m][j+1]=dp[i][j]+G[(i+m-1)%m][j+1];
				fa[(i+m-1)%m][j+1]=i*n+j;
			}
			if(dp[i][j+1]>dp[i][j]+G[i][j+1])
			{
				dp[i][j+1]=dp[i][j]+G[i][j+1];
				fa[i][j+1]=i*n+j;
			}
			if(dp[(i+m+1)%m][j+1]>dp[i][j]+G[(i+m+1)%m][j+1])
			{
				dp[(i+m+1)%m][j+1]=dp[i][j]+G[(i+m+1)%m][j+1];
				fa[(i+m+1)%m][j+1]=i*n+j;
			}
		}
		//	dp[i][j+1]=min(dp[i][j],min(dp[(i+m-1)%m][j],dp[(i+m+1)%m][j]))+G[i][j+1];
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<fa[i][j]<<' ';
		cout<<endl;
	}*/
	l=0;
	minn=dp[0][n-1];
	for(int i=1;i<m;i++)
		if(dp[i][n-1]<minn)
		{
			minn=dp[i][n-1];
			l=i;
		}
}

void print_path2(int x,int y)
{
	int c=0;
	for(;;)
	{
		int fx=fa[x][y]/n;
		int fy=fa[x][y]%n;
		dir[c++]=x+1;
		if(fx==x&&fy==y)
			break;
		x=fx;
		y=fy;
	}
	cout<<dir[0];
	for(int i=1;i<c;i++)
		cout<<' '<<dir[i];
}

int main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>m>>n)
	{
		init();
		solve();
		//cout<<l<<' '<<n-1<<endl;
		print_path2(l,n-1);
		cout<<endl;
		cout<<minn<<endl;
	}
	return 0;
}
