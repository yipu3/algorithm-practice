#include<cstdio>
#include<cstring>
char map[105][105];
int vis[105][105];
int m,n;
void dfs(int x,int y)
{
	if(map[x][y]!='@'||vis[x][y]||x<0||x>=m||y<0||y>=n)
		return;
	else
	{
		vis[x][y]=1;
		dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
		dfs(x,y-1);		dfs(x,y+1);
		dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
	}
}
int main()
{
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(m==0)
			break;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++)
			//for(int j=0;j<n;j++)
			{
				scanf("%s",map[i]);
				getchar();
			}
		/*for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}*/
		int cnt=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(!vis[i][j]&&map[i][j]=='@')
				{
					cnt++;
					dfs(i,j);
				}
		printf("%d\n",cnt);
	}
	return 0;
}
