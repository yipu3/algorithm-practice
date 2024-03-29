#include<iostream>
#define mod 1000000007
#define maxn 1005
int maze[maxn];
long long dp[maxn];
int n;
/*void search(int x)
{
	if(x==n)
		return;
	no[x]++;
	if(no[x]%2==1)
	{
		step++;
		step%=maxn;
		search(maze[x]-1);
	}
	else
	{
		step++;
		step%=maxn;
		search(x+1);
	}
}*/
using namespace std;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>maze[i];
	dp[1]=0;
	for(int i=1;i<=n;i++)
	{
			dp[i+1]=(dp[i]*2+2-dp[maze[i]]+mod)%mod;
	}
	cout<<dp[n+1]%mod<<endl;
	return 0;
}
