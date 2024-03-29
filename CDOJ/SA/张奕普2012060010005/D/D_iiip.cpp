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

int vis[9999];

int isprime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

struct node
{
	int val;
	int step;
};

queue<node> q;

int bfs(int a,int b)
{
	node u;
	u.val=a;u.step=0;
	vis[a]=1;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(u.val==b)
			return u.step;
		for(int i=0;i<10;i++)
		{
			node nn;
			nn.step=u.step+1;
			nn.val=(u.val/10)*10+i;
			if(isprime(nn.val)&&!vis[nn.val])
			{
				vis[nn.val]=1;
				q.push(nn);
			}
			nn.val=(u.val/100)*100+i*10+u.val%10;
			if(isprime(nn.val)&&!vis[nn.val])
			{
				vis[nn.val]=1;
				q.push(nn);
			}
			nn.val=(u.val/1000)*1000+i*100+u.val%100;
			if(isprime(nn.val)&&!vis[nn.val])
			{
				vis[nn.val]=1;
				q.push(nn);
			}
			if(i!=0)//no leading zeros
			{
				nn.val=u.val%1000+i*1000;
				if(isprime(nn.val)&&!vis[nn.val])
				{
					vis[nn.val]=1;
					nn.step=u.step+1;
					q.push(nn);
				}
			}
		}
	}
	return -1;
}

int main()
{
	int t;
	cin>>t;
	int ans;
	while(t--)
	{
		int a,b;
		memset(vis,0,sizeof(vis));
		while(!q.empty()) q.pop();
		scanf("%d%d",&a,&b);
		ans=bfs(a,b);
		if(ans==-1)
			printf("Impossible\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
