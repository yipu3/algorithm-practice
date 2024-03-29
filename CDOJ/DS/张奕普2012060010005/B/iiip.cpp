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

int n,m,c[100010];

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
	while(x<=n)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

int main()
{
	cin>>n>>m;
	int temp;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		add(i,temp);
	}
	while(m--)
	{
		int s,x,w;
		cin>>s>>x>>w;
		if(s==0)
			cout<<sum(w)-sum(x-1)<<endl;
		else
			add(x,w);
	}
	return 0;
}
