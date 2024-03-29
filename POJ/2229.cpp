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
#include<cmath>
#include<map>
#include<fstream>
#include<sstream>
#include<string>

typedef long long ll;
using namespace std;

int dp[1000005];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int n;
	scanf("%d",&n);
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(i%2==1)
			dp[i]=dp[i-1];
		else
			dp[i]=dp[i-1]+dp[i/2];
		dp[i]%=1000000000;
	}
	printf("%d\n",dp[n]);
	return 0;
}
