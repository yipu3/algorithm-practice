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
#include<fstream>
#include<sstream>
#include<string>

typedef long long ll;
using namespace std;

struct node
{
	int x,y;
}a[105];

int maze[105][105],vis[105];
int n;

int ab(int x)
{
	if(x<0)
		x=-x;
	return x;
}

bool judge(const node &a,const node &b)
{
	int t1=ab(a.x-b.x),t2=ab(a.y-b.y);
	if(t1+t2<=1000)
		return true;
	return false;
}

bool cmp(const node &a,const node &b)
{
	int t1=a.x+a.y,t2=b.x+b.y;
	return t1<t2;
}

bool dfs(int s,int t)
{
	if(s==t)
		return true;
	vis[s]=1;
	for(int i=0;i<n;i++)
		if(!vis[i]&&maze[s][i]==1)
		{
			if(dfs(i,t))
				return true;
		}
	return false;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		memset(maze,0,sizeof(maze));
		n+=2;
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(judge(a[i],a[j]))
					maze[i][j]=maze[j][i]=1;
		if(dfs(0,n-1))
			printf("happy\n");
		else
			printf("sad\n");
	}
	return 0;
}
