/************************************************
 * Author:		iiip
 * File name:		10003.cpp
 * Created time:	2014/4/5 9:41:20
 * Email:		firstawhois@gmail.com
 * *********************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cmath>
#define ll long long
using namespace std;

ll dp[51][51];
ll cut[51];
ll l,n;
int main()
{
	while(cin>>l)
	{
		if(l==0)	
			break;
		cin>>n;
		for(ll i=1;i<=n;i++)
			cin>>cut[i];
		cut[0]=0;cut[n+1]=l;
		for(int i=0;i<=n;i++)
			dp[i][i+1]=0;
		for(int j=2;j<=n+1;j++)
			for(int i=0;i+j<=n+1;i++)
			{
				dp[i][i+j]=LLONG_MAX;
				for(int k=i+1;k<i+j;k++)
					dp[i][j+i]=min(dp[i][j+i],dp[i][k]+dp[k][i+j]+cut[j+i]-cut[i]);
			}
		cout<<"The minimum cutting is "<<dp[0][n+1]<<'.'<<endl;
	}
	return 0;
}
