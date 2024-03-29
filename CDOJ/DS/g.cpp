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
#define MAXN 400100

typedef long long ll;
using namespace std;

ll sumv[MAXN],lmax[MAXN],rmax[MAXN],ans[MAXN];

typedef struct node
{
	int sum,lmax,rmax,ans;
}node;

void maintain(int id)
{
	int lc=id*2,rc=id*2+1;
	ans[id]=max(rmax[lc]+lmax[rc],max(ans[lc],ans[rc]));
	sumv[id]=sumv[lc]+sumv[rc];
	lmax[id]=max(lmax[lc],sumv[lc]+lmax[rc]);
	rmax[id]=max(rmax[rc],sumv[rc]+rmax[lc]);
}

void build(int id,int l,int r)
{	
	int lc=id*2,rc=id*2+1;
	if(l==r)
	{
		scanf("%lld",&sumv[id]);
		lmax[id]=rmax[id]=ans[id]=sumv[id];
	}
	else
	{
		int mid=(l+r)/2;
		build(lc,l,mid);
		build(rc,mid+1,r);
		maintain(id);
	}
}

void update(int id,int L,int R,int x,int w)
{
	int lc=id*2,rc=id*2+1;
	if(L==R)
	{
		sumv[id]=lmax[id]=rmax[id]=ans[id]=w;
		return;
	}
	else
	{
		int mid=(L+R)/2;
		if(x<=mid)
			update(lc,L,mid,x,w);
		if(x>mid)
			update(rc,mid+1,R,x,w);
		maintain(id);
	}
}

node query(int id,int L,int R,int l,int r)
{
	int lc=id*2,rc=id*2+1;
	if(l<=L&&r>=R)
	{
		node temp;
		temp.sum=sumv[id];
		temp.lmax=lmax[id];
		temp.rmax=rmax[id];
		temp.ans=ans[id];
		return temp;
	}
	else
	{
		int mid=(L+R)/2;
		node temp,ln,rn;
		if(r<=mid)
		{
			temp=query(lc,L,mid,l,r);
			return temp;
		}
		if(l>mid)
		{
			temp=query(rc,mid+1,R,l,r);
			return temp;
		}
		else
		{
			ln=query(lc,L,mid,l,r);
			rn=query(rc,mid+1,R,l,r);
			temp.sum=ln.sum+rn.sum;
			temp.ans=max(ln.rmax+rn.lmax,max(ln.ans,rn.ans));
			temp.lmax=max(ln.lmax,ln.sum+rn.lmax);
			temp.rmax=max(rn.rmax,rn.sum+ln.rmax);
			return temp;
		}
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n);
//	for(int i=1;i<=7;i++)
//		cout<<rmax[i]<<' ';
//	cout<<endl;
	while(m--)
	{
		int s,a,b;
		scanf("%d%d%d",&s,&a,&b);
		if(s==1)
			update(1,1,n,a,b);
		if(s==0)
		{
			node temp;
			temp=query(1,1,n,a,b);
			printf("%d\n",temp.ans);
		}
	}
	return 0;
}
