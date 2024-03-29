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
#define MAXN 50010

typedef long long ll;
using namespace std;

int c[32770];
int lock[MAXN];
int a[MAXN],b[MAXN];

int lowbit(int x)
{
	return x&-x;
}

int sum(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}

void add(int x,int d)
{
	while(x<=32768)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

int main()
{
	int n;
	cin>>n;
	ll ans=0;
	for(int i=0;i<n;i++)
		cin>>lock[i];
	for(int i=0;i<n;i++)
	{
		add(lock[i],1);
		a[i]=sum(lock[i]-1);
	}
/*	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;*/
	memset(c,0,sizeof(c));
	for(int i=n-1;i>=0;i--)
	{
		add(lock[i],1);
		b[i]=sum(lock[i]-1);
	}
/*	for(int i=0;i<n;i++)
		cout<<b[i]<<' ';
	cout<<endl;*/
	for(int i=1;i<n-1;i++)
		ans+=a[i]*b[i];
	cout<<ans<<endl;
	return 0;
}
