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
#define INF 100000000

typedef long long ll;
using namespace std;

int maze[15][15],dp[15][380],ha[380];

int main()
{
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
//	cout<<(1<<m)<<endl;
	for(int i=0;i<(1<<m);i++)
		if((i&(i<<1))==0)
			ha[cnt++]=i;
//	cout<<cnt<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&maze[i][j]);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		int no=0;
		for(int j=0;j<m;j++)
			if(maze[i][j]==0)
				no=(no|(1<<j));
		for(int j=0;j<cnt;j++)
		{
			int t1=ha[j];
			if((t1&no)==0)
			{
				for(int k=0;k<cnt;k++)
				{
					int t2=ha[k];
					if((t1&t2)==0&&dp[i][k])
					{
						dp[i+1][j]+=dp[i][k];
						dp[i+1][j]%=INF;
					}
				}
			}
		}
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<cnt;j++)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}*/
	int ans=0;
	for(int i=0;i<cnt;i++)
	{
		ans+=dp[n][i];
		ans%=INF;
	}
	printf("%d\n",ans);
	return 0;
}
