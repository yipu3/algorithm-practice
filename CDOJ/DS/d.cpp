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
#define MAXN 100005

typedef long long ll;
using namespace std;
ll sumv[8*MAXN],lazy[8*MAXN];
set<int> sy;
map<int,int> ry;

struct star
{
	ll x,y,w;
	int flag;
}s1[MAXN],s2[2*MAXN];

bool cmp(const struct star &a,const struct star &b)
{
	if(a.x<b.x)
		return 1;
	else
		return 0;
}

void build(ll id,ll l,ll r)
{
	int lc=id*2,rc=id*2+1;
	lazy[id]=0;
	if(l==r)
	{
		sumv[id]=0;lazy[id]=0;
	}
	else
	{
		ll mid=(l+r)/2;
		build(lc,l,mid);
		build(rc,mid+1,r);
		sumv[id]=lazy[id]=0;
	}
}

void maintain(ll id,ll L,ll R)
{
	if(lazy[id]!=0)
	{
		lazy[id*2]+=lazy[id];
		sumv[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		sumv[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
}

void update(ll id,ll L,ll R,ll w,ll l,ll r)
{
	int lc=id*2,rc=id*2+1;
	if(l<=L&&r>=R)
	{
		lazy[id]+=w;
		sumv[id]+=w;
	}
	else
	{
		maintain(id,L,R);
		ll mid=(L+R)/2;
		if(l<=mid)
			update(lc,L,mid,w,l,r);
		if(r>mid)
			update(rc,mid+1,R,w,l,r);
		sumv[id]=max(sumv[lc],sumv[rc]);
	}
}

int main()
{
	int n,W,H;
	scanf("%d%d%d",&n,&W,&H);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&s1[i].x,&s1[i].y,&s1[i].w);
	}
	int j=0;
	for(int i=0;i<n;i++)
	{
		s2[j]=s1[i];s2[j].x-=W;
		j++;
		s2[j]=s1[i];s2[j].w=(-s1[i].w);
		j++;
		sy.insert(s1[i].y);
		sy.insert(s1[i].y-H);
	}
	sort(s2,s2+j,cmp);
	int yn=1;
	for(set<int>::iterator i=sy.begin();i!=sy.end();i++)
	{
		int temp=*i;
		ry[temp]=yn;
		yn++;
	}
	build(1,1,yn);
	ll ans=0;
	for(int i=0;i<j;i++)
	{
			//cout<<ry[s2[i].y-H]<<' '<<ry[s2[i].y]<<' '<<s2[i].w<<endl;
			update(1,1,yn,s2[i].w,ry[s2[i].y-H],ry[s2[i].y]);
			ans=max(ans,sumv[1]);
//			for(int k=1;k<=7;k++)
//				cout<<sumv[i]<<' ';
//			cout<<endl;
	}
	printf("%d",ans);
	return 0;
}
