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
#define INF 1000000007

typedef long long ll;
using namespace std;

int a[100005];
int vis[100005];
int ans,cnt;

void dfs(int x)
{
	cnt++;
	vis[x]=1;
	if(vis[a[x]])
	{
		return;
	}
	else
	{
		dfs(a[x]);
	}
}

int gcd(int c,int d)
{
	if(d==0)
		return c%INF;
	else
		return gcd(d,c%d);
}

int lcm(int c,int d)
{
	return c/gcd(c,d)*d;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			vis[i]=0;
		}
		ans=1;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				cnt=0;
				dfs(i);
//				cout<<"cnt:"<<cnt<<endl;
//				cout<<"gcd:"<<gcd(ans,cnt)<<endl;
				ans=lcm(ans,cnt);
//				cout<<"ans:"<<ans<<endl;
				ans%=INF;
			}
		ans%=INF;
		cout<<ans<<endl;
	}
	return 0;
}
