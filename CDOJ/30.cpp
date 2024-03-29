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
#define INF 10000005

typedef long long ll; 
using namespace std;

int maze[105][105],vis[105],d[105],n,m;

void init()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			maze[i][j]=INF;
		maze[i][i]=0;
	}
	for(int i=0;i<n;i++)
		vis[i]=0;
	for(int i=0;i<n;i++)
		d[i]=INF;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	while(~scanf("%d%d",&n,&m)&&!(n==0&&m==0))
	{
		init();
		while(m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			maze[u-1][v-1]=min(w,maze[u-1][v-1]);
			maze[v-1][u-1]=maze[u-1][v-1];
		}
		d[0]=0;
		/*	for(int i=0;i<n;i++)
			cout<<d[i]<<" ";
			cout<<endl;*/
		while(1)
		{
			int v=-1;
			for(int u=0;u<n;u++)
				if(!vis[u]&&(v==-1||d[u]<d[v]))
					v=u;
			if(v==-1)
				break;
			vis[v]=1;
			for(int u=0;u<n;u++)
				d[u]=min(d[u],d[v]+maze[v][u]);
		}
		printf("%d\n",d[n-1]);
	}
	return 0;
}
