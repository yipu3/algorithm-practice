#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define maxn 100000
using namespace std;
//int fa[maxn];
vector<int> G[maxn];
bool locked[maxn];
int key[maxn];
bool vis[maxn];
queue<int> q;
/*nt find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}*/
void bfs()
{
	q.push(0);
	vis[0]=true;
	if(key[0]!=0)
		locked[key[0]]=false;
	while(!q.empty())
	{
		int h=q.front();
		q.pop();
		int len=G[h].size();
		if(key[h]!=0)
			locked[key[h]]=false;
		for(int i=0;i<len;i++)
		{
			int now=G[h][i];
			if(!locked[now]&&!vis[now])
			{
				vis[now]=1;
				q.push(now);
			}
			else 
				continue;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		//for(int i=0;i<n;i++)//init fa
			//fa[i]=i;
		for(int i=0;i<n;i++)
			G[i].clear();
		while(m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
			//fa[find(u)]=find(v);
		}
		int k;
		scanf("%d",&k);
		memset(locked,0,sizeof(locked));
		memset(key,0,sizeof(key));
		while(k--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			locked[x]=1;
			key[y]=x;
		}
		memset(vis,0,sizeof(vis));
		bfs();
		bool flag=true;
		for(int i=0;i<n;i++)
			if(vis[i]!=1)
			{
				printf("Case #%d: No\n",cas);
				flag=false;
				break;
			}
		if(flag)
			printf("Case #%d: Yes\n",cas);
	}
}
