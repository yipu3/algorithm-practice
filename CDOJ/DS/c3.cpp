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

int a[100005];

struct Tree
{
	int left,right;
	int sum;
	int flag;
	int add;
}tree[4*MAXN];

void build(int id,int l,int r)
{
	tree[id].left=l;
	tree[id].right=r;
	tree[id].flag=0;
	tree[id].sum=0;
	if(l==r)
	{
		tree[id].sum=a[l];
		tree[id].flag=1;
		return;
	}
	if(l<r)
	{
		int mid=l+(r-l)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	}
}

void update(int id,int l,int r,int w)
{
	if(tree[id].left==l&&tree[id].right==r)
	{
		tree[id].flag=1;
		tree[id].add+=w;
		return;
	}
	tree[id].sum+=w*(r-l+1);
	int mid=l+(r-l)/2;
	if(r<=mid)
		update(id*2,l,r,w);
	else if(l>mid)
		update(id*2+1,l,r,w);
	else
	{
		update(id*2,l,mid,w);
		update(id*2+1,mid+1,r,w);
	}
}

ll query(int id,int l,int r)
{
	ll ans=0;
	if(tree[id].flag)
		ans+=tree[id].add*(l-r+1);
	if(tree[id].left==l&&tree[id].right==r)
	{
		ans+=tree[id].sum;
		return ans;
	}
	int mid=tree[id].left+(tree[id].right-tree[id].left)/2;
	if(r<=mid)
		return ans+query(id*2,l,r);
	else if(l>mid)
		return ans+query(id*2+1,l,r);
	else
		return ans+query(id*2,l,mid)+query(id*2+1,mid+1,r);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(m--)
	{
		int s;
		cin>>s;
		if(s)
		{
			int l,r,w;
			cin>>l>>r>>w;
			update(1,l,r,w);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			for(int i=0;i<=9;i++)
				cout<<tree[i].sum<<' ';
			cout<<endl;
			cout<<query(1,1,n)<<endl;
		}
	}
	return 0;
}
