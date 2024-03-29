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
ll dp[19][10],cnt[19];

//[1,n]
ll solve(ll n)
{
	int len=0,last=20;
	ll ans=0;
	int num[20];
	while(n)
	{
		num[len++]=n%10;
		n/=10;
	}
//	cout<<"len:"<<len<<endl;
	for(int i=len-1;i>=0;i--)
	{
//		cout<<"num:"<<num[i]<<endl;
		if(i==len-1)
		{
			ans+=cnt[len-1];
			for(int j=1;j<num[i];j++)
				ans+=dp[len][j];
		}
		else
		{
			for(int j=0;j<num[i];j++)
				if(j-last>=2||last-j>=2)
				{
					ans+=dp[i+1][j];
	//				cout<<"!:"<<dp[i+1][j];
				}
		}
		if(i==0&&(num[i]-last>=2||last-num[i]>=2))
			ans++;
//		cout<<ans<<endl;
		if(num[i]-last<2&&last-num[i]<2)
		{
//			cout<<num[i]<<' '<<last<<endl;
//			cout<<"Y"<<endl;
			break;
		}
		last=num[i];
	}
	return ans;
}

int main()
{
	ll a,b;
	//dp��ǰ��0,i=len,j=up
	for(int i=0;i<10;i++)
		dp[1][i]=1;
	cnt[1]=9;
	for(int i=2;i<=18;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(k-j>=2||j-k>=2)
					dp[i][j]+=dp[i-1][k];
			}
			if(j!=0)
				cnt[i]+=dp[i][j];
		}
		cnt[i]+=cnt[i-1];
	}
//	cout<<cnt[12]<<endl;
	while(~scanf("%lld%lld",&a,&b))
	{
		ll ans1=solve(b);
//		cout<<ans1<<endl;
		ll ans2=solve(a-1);
		printf("%lld\n",ans1-ans2);
	}
	return 0;
}
