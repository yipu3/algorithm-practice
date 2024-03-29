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
#include<map>
#include<cmath>
#include<sstream>
#include<string>
#define MAXN 300005
#define INF 1000000009

typedef long long ll;
using namespace std;

int addv[4*MAXN],sumv[4*MAXN],a[MAXN];
ll f[MAXN];

void build(int id,int l,int r)
{
	if(l==r)
	{
		sumv[id]=a[l];
		addv[id]=0;
		return;
	}
	else
	{
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		sumv[id]=sumv[id*2]+sumv[id*2+1];
		addv[id]=0;
	}
}

void maintain(int id,int l,int r)
{
	if(addv[id]!=0)
	{
		mid=(l+r)/2;
		addv[id*2]=1;
		addv[id*2+1]=1;
		sumv[id*2]+=s[mid]-s[l-1];
		sumv[id*2+1]+=s[r]-s[mid];
		addv[id]=0;
	}
}

void update(int id,int L,int R,int l,int r,int w)
{
	if(l<=L&&r>=R)
	{
		addv[id]=1;
		sumv[id]+=s[r]-s[l-1];
		return;
	}
	else
	{
		maintain(id,L,R);
		int mid=(L+R)/2;
		if(l<=mid)
			update(id*2,L,mid,l,r,w);
		if(r>mid)
			update(id*2+1,mid+1,R,l,r,w);
		sumv[id]=sumv[id*2]+sumv[id*2+1];
	}
}

int query(int id,int L,int R,int l,int r)
{
	if(l<=L&&r>=R)
	{
		return sumv[id];
	}
	else
	{
		maintain(id,L,R);
		int mid=(L+R)/2;
		int ans=0;
		if(l<=mid)
		{
			ans+=query(id*2,L,mid,l,r);
			ans%=INF;
		}
		if(r>mid)
		{
			ans+=query(id*2+1,mid+1,R,l,r);
			ans%=INF;
		}
		return ans;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	f[1]=f[2]=1;
	for(int i)
	for(int i=3;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	while(m--)
	{
		int q,l,r;
		cin>>q>>l>>r;
		if(q==1)
			update(1,1,n,l,r,f[r-l+1]);
		else
			cout<<query(1,1,n,l,r);
	}
	return 0;
}
